# Week 6

## [Problem 1: Linked_Queue 구현](problem1)

- 문자들의 Linked Queue를 테스트하는 프로그램 구현
- 명령어
  - `+<c>` : AddQ
  - `-` : DeleteQ
  - S : Show
  - Q : Quit

## [Problem 2: Queue_simulation](problem2)

- 프린터 작업에 대한 simulation
  - Linked Queue로 프린터 큐 구현
- 시뮬레이션 방식
  - `current_time`을 증가시키면서 매 시각 가상의 프린트 job을 처리

```
while(current_time < MAX_SIMUL_TIME) {
... ++current_time;
}
```

- job
  - `id` – job의 ID
  - `arrival_time` – job이 도착한 시간
  - `duration` – job의 프린트 시간
- 새로운 job의 도착 (`is_job_arrived()`)
  - `random()` 을 호출, 반환값이 정해진 값보다 작으면 도착한 것으로 간주
  - 새 job을 큐에 삽입 (`insert_job_into_queue (id, arrival_time, duration)`)
    - 새 job의 프린트 시간 `duration = random() \* MAX_PRINTING_TIME + 1`
- 프린트 완료 (`is_printer_idle()`)
  - 남은 프린트 시간이 0 이하면 완료된 것임
  - 큐에서 다음 job을 가져와 실행 (`process_next_job()`)
    - `current_job_id = job.id`
    - `remaining_time = job.duration`
- job 을 프린트 하기
  - 프린트 시간을 매 시각 하나씩 감소시키는 것을 프린트가 되는 것으로 간주
    - 매 시각: `--remaining_time`
- 난수 발생 함수
  - `rand()` 함수
    - 0 ~ `RAND_MAX` 까지의 정수를 무작위로 반환
  - `srand()`함수
    - 매번 새로운 난수를 발생시키기 위하여 사용
    - `srand(time(NULL))`
- 0.0 ~ 1.0 까지의 실수를 무작위로 반환
  - `return rand()/(double)RAND_MAX;`
- 1 ~ 5 까지의 정수를 무작위로 반환
  - `return (int)(5\*(rand()/(double)RAND_MAX)) + 1;`
