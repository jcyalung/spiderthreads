# spiderthreads
multithreaded web crawler written in C++.

## Usage
```shell
  SpiderThread -s <STARTING_URL> -n <NUMBER_OF_WEBSITES> [OPTIONS]
  SpiderThread -c <CONTINUE_LOG_FILE> [OPTIONS]

:
  --help                         HELP print this message
  -c [ --continue ] arg          CONTINUE_LOG_FILE to resume from [.log | .txt]
  -h [ --history_log ] arg       HISTORY_FILE to write websites visited [.log 
                                 |.txt]
  -t [ --threads ] arg (=1)      THREADS maximum number of threads
  -n [ --n_websites ] arg (=100) NUMBER_OF_WEBSITES max number of websites to 
                                 crawl
  -s [ --start ] arg             STARTING URL url to start from
  -d [ --delay ] arg (=300)      DELAY delay in ms for politeness
  -l [ --log ] arg               LOG_FILE to save PROGRESS
```
i'm not good at documentation

## copyright
dont copy pls