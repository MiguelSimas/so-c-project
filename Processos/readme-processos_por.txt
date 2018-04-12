[pt]
Este programa, designado por process-run.py, permite perceber como é que
o estado de um processo muda à medida que ele é executado num CPU. 
Como descrito no capítulo, os processos podem-se encontrar nos seguintes estados: 

RUNNING - the process is using the CPU right now
READY   - the process could be using the CPU right now but (alas) some other process is
WAITING - the process is waiting on I/O (e.g., it issued a request to a disk)
DONE    - the process is finished executing

No trabalho de casa, vamos verificar como é que os processos variam à medida que o programa é executado e aprender um pouco melhor como tudo isto funciona. 
Para iniciar um programa e obter as opções, executar:

prompt> python3 process-run.py -h

(nota: deverá instalar python3, usando o comando 'sudo apt-get install python3'):

O que vê após executar este comando é o seguinte:

Usage: process-run.py [options]

Options:
  -h, --help            show this help message and exit
  -s SEED, --seed=SEED  the random seed
  -l PROCESS_LIST, --processlist=PROCESS_LIST
                        a comma-separated list of processes to run, in the
                        form X1:Y1,X2:Y2,... where X is the number of
                        instructions that process should run, and Y the
                        chances (from 0 to 100) that an instruction will use
                        the CPU or issue an IO
  -L IO_LENGTH, --iolength=IO_LENGTH
                        how long an IO takes
  -S PROCESS_SWITCH_BEHAVIOR, --switch=PROCESS_SWITCH_BEHAVIOR
                        when to switch between processes: SWITCH_ON_IO,
                        SWITCH_ON_END
  -I IO_DONE_BEHAVIOR, --iodone=IO_DONE_BEHAVIOR
                        type of behavior when IO ends: IO_RUN_LATER,
                        IO_RUN_IMMEDIATE
  -c                    compute answers for me
  -p, --printstats      print statistics at end; only useful with -c flag
                        (otherwise stats are not printed)

A opção mais importante é a PROCESS_LIST (indicado por -l ou --processlist) que especifica exatamente o que cada programa (ou processo) irá fazer. 
Um processo consiste em instruções e cada instrução pode fazer uma das seguintes tarefas:
--- usar o CPU
--- executar uma E/S (e esperar que esta termine)

Quando um processo usa o CPU (e não a E/S), ele deve simplesmente alternar entre RUNNING no CPU ou estar READY para ser executado. No comando em seguida mostra-se uma execução onde apenas há um programa a ser executado e que utiliza CPU (e não E/S):

prompt> python3 process-run.py -l 5:100 

Produz o seguinte rasto (trace) do que acontece quando se correm estes processos:

"Process 0
  cpu
  cpu
  cpu
  cpu
  cpu

Important behaviors:
System will switch when
the current process is FINISHED or ISSUES AN IO
  After IOs, the process issuing the IO will
run LATER (when it is its turn)"

No exemplo, o processo que especificamos é 5:100 que quer dizer que consiste em 5 instruções em que a possibilidade de uma instrução ser do tipo CPU é 100%.

Podemos ver o que acontede ao processo utilizando a flag -c, que mostra o resultado da computação:

prompt> python3 process-run.py -l 5:100 -c
Time     PID: 0        CPU        IOs
  1     RUN:cpu          1
  2     RUN:cpu          1
  3     RUN:cpu          1
  4     RUN:cpu          1
  5     RUN:cpu          1

Este resultado é o esperado: 
O processo corre simplemente no estado RUN e termina, utilizando o CPU todo o tempo, mantendo o CPU ocupado em toda a  execução, não realizando nenhuma operação de E/S.

Vamos tornar o exemplo mais complexo utilizando dois processos em que ambos usam o CPU:

prompt> python3 process-run.py -l 5:100,5:100
Produz-se o seguinte rasto: 
"
Process 0
  cpu
  cpu
  cpu
  cpu
  cpu

Process 1
  cpu
  cpu
  cpu
  cpu
  cpu

Important behaviors:
System will switch when
The current process is FINISHED or ISSUES AN OI
After IOs, the process issuing the IO will
run later (when it is its turn)
"
Neste caso, dois processos diferentes concorrem para o mesmo CPU. O que acontece quando o sistema os corre? Vamos descobrir.

prompt> ./process-run.py -l 5:100,5:100 -c
Time     PID: 0     PID: 1        CPU        IOs
  1     RUN:cpu      READY          1
  2     RUN:cpu      READY          1
  3     RUN:cpu      READY          1
  4     RUN:cpu      READY          1
  5     RUN:cpu      READY          1
  6        DONE       RUN:cpu          1
  7        DONE       RUN:cpu          1
  8        DONE       RUN:cpu          1
  9        DONE       RUN:cpu          1
 10        DONE      RUN:cpu          1

Nas colunas PID:0 e PID:1 estão indicados os estados dos dois processos em execução. 
O primeiro processo com "process ID" 0 corre, enquanto o processo 1 está no estado "READY" e espera até que o processo o termine. 
Quando o processo 0 termina,  ele move-se para o o estado DONE, enquanto o processo 1 corre.


Vamos olhar para um outro exemplo antes de avançar para algumas questões. 
No exemplo seguinte um processo lança uma E/S. 
Especificam-se as E/S utilizando a flag -L. O valor a seguir à flag, indica as unidades de tempo que a E/S precisa para terminar a sua tarefa.
Repare-se que agora se indica que o processo vai correr com toda a certeza uma E/S.

prompt> python3 process-run.py -l 3:0 -L 5
O rasto produzido do que acontece quando se corre este processo:

"
Process 0
  io
  io
  io

Important behaviors:
System will switch when
The current process is FINISHED or ISSUES AN OI
After IOs, the process issuing the IO will
run later (when it is its turn)
"

prompt> python3 process-run.py -l 3:0 -L 5 -c
Time     PID: 0        CPU        IOs
  1  RUN:io-start          1
  2     WAITING                     1
  3     WAITING                     1
  4     WAITING                     1
  5     WAITING                     1
  6* RUN:io-start          1
  7     WAITING                     1
  8     WAITING                     1
  9     WAITING                     1
 10     WAITING                     1
 11* RUN:io-start          1
 12     WAITING                     1
 13     WAITING                     1
 14     WAITING                     1
 15     WAITING                     1
 16*       DONE

Como se pode ver, o program lança três E/S. Enquando cada E/S é executada,
o processo adquire o estado WAITING e enquanto o "device driver" está ocupado 
a servir a E/S, o CPU está parado (idle).

Se imprimirmos as estatísticas (correr o mesmo comando acrescentando a flag '-p') 
conseguimos ver os resuldados do comportamento:

Stats: Total Time 16
Stats: CPU Busy 3 (18.75%)
Stats: IO Busy  12 (75.00%)

Como se pode ver, o rasto mostra que se utilizaram 16 tics do relógio mas o CPU
apenas esteve ocupado em 20% do tempo. 
O "device driver" de E/S esteve bastante ocupado.
Em geral, desejamos manter os "devices" ocupados, pois é uma forma de garantir que há uma melhor utilização dos recursos disponíveis.

Existem ainda algumas outras flags importantes: 
  -s SEED, --seed=SEED  the random seed  
     Esta flag dá-nos a oportunidaded de criar diferentes tipos de trabalhos (jobs) de forma aleatória.   
  -L IO_LENGTH, --iolength=IO_LENGTH
    Esta flag determina quanto tempo demora uma E/S ser completada (por defeito, 5 tics)
  -S PROCESS_SWITCH_BEHAVIOR, --switch=PROCESS_SWITCH_BEHAVIOR
    Identifica em que situações se troca entre processos: SWITCH_ON_IO, SWITCH_ON_END
    determinando quando ocorre uma troca de um processo para outro:
     - SWITCH_ON_IO, o sistema troca quando ocorre um evento E/S
     - SWITCH_ON_END, o sistema vai apenas trocar quando o processo corrente termina
  -I IO_DONE_BEHAVIOR, --iodone=IO_DONE_BEHAVIOR
    Tipo de comportamento quando E/S termina: IO_RUN_LATER,IO_RUN_IMMEDIATE
    Este comando determina quando é que um processo corre após ter executado uma E/S:
    - IO_RUN_IMMEDIATE: troca de processo imediatamente
    - IO_RUN_LATER: troca de processo quando é natural fazê-lo (e.g. dependendo do comportamento  de troca de processo definido no PROCESS_SWITCH_BEHAVIOR)

Agora responde às questões do trabalho prático para aprender mais.
