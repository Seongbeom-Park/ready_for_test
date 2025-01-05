# 임용 코딩 테스트 준비
## 코테 연습 환경 설정
* `제2차실기시험시행계획`에 제시된 툴 설치

### [2024년] Dev C++(TDM-GCC 4.9.2 Compiler)
1. 구글링을 통해 **정확히** 일치하는 버전을 설치 (GCC 버전에 따라 문법이 다를 수 있음)

    ```
    dev-cpp 5.11 tdm-gcc 4.9.2 setup
    ```

1. 언어 설정 변경
   
    - Tools >> Environment Options >> Genenral >> Language

    - 도구 >> 환경설정 >> 일반 >> 언어

## 시험장에서 할 일
### 1. 프로젝트 폴더 생성

  - 하드디스크 D 또는 USB에 문제별 폴더 생성: aa, bb, cc, dd, ee, ff

  - 시험 시작 시 미리 만들어두는게 편함

### 2. 프로젝트 생성
  - Dev-C++ >> 파일 >> 새로 만들기 >> 프로젝트 >> Basic >> Console Application >> C >> 기본 언어로 설정 >> 프로젝트명(aa) >> 확인

### 3. 저장 위치를 생성한 프로젝트 폴더를 지정

### 4. 컴파일 후 실행(F11)

### 5. 프로젝트 폴더에`main.c`파일 저장
  - 정상적으로 빌드 후 실행 되었는지 확인

  - 동작하지 않는다면 프로젝트 생성 단계 확인

### 6. 디버깅용 코드 삽입 후 컴파일 및 실행
  ```c
  #define DEBUG
  #ifdef DEBUG
  #define log(msg...) printf(msg)
  #else
  #define log(msg...)
  #endif

  ...

  int main(int argc, char *argv[]) {
    log("test");
    return 0;
  }
  ```

  - `#define DEBUG`가 있으면 `log(msg...);`가 `printf(msg...);`와 동일하게 동작함
  - `//#define DEBUG`와 같이 주석처리 되면 `log(...);`가 `;`으로 변환되어 제거됨

#### `log()` 사용법 예시
  ```c
  //#define DEBUG
  #ifdef DEBUG
  #define log(msg...) printf(msg)
  #else
  #define log(msg...)
  #endif
  
  #include <stdio.h>
  #include <stdlib.h>
  
  int main(int argc, char *argv[]) {
    log("Project aa\n");

    int myNumber;
    scanf("%d", &myNumber);
    
    printf("myNumber: %d\n", myNumber);
    if (myNumber > 100) log("[ERROR] too large myNumber: %d\n", myNumber);
    
    return 0;
  }
  ```

## 팁
### 주석 처리 단축키: `Ctrl + /`
### 컴파일 및 실행 단축키: `F11`
### `.layout`파일
  - 프로젝트를 닫을 때 생성됨 (e.g., 새 프로젝트 생성, 프로젝트 종료, dev-c++ 프로그램 종료)
    - 파일 >> 새로 만들기 >> 프로젝트
    - 파일 >> 프로젝트 종료
    - 파일 >> Dev-C++ 종료
    - `Alt + F4`
