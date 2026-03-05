*This project has been created as part of the 42 curriculum by <cjung>*

#Description
이번 과제는 get_next_line입니다.
입력값 및 fd로 부터 들어온 데이터에서 한 줄(개행문자 기준)을 반환합니다.
반복 실행시에도 한줄 씩만 반환해야합니다.
읽을게 없거나 오류 발생 시 NULL을 반환합니다.
file을 읽을 때와 표준 입력시 둘 다 작동해야합니다.
개행문자가 포함되어있지 않은 경우를 제외하고 개행문자 까지 반환해야합니다.
헤더는 get_next_line()의 원형을 포함해야합니다.
모든 헬퍼함수들은 get_next_line_utils.c에 넣으세요.
compiler call에 -D BUFFER_SIZE=n을 넣으시되 이게 없어도 작동되게 하세요.

파일을 읽는중에 파일을 수정하지마세요.
이진 파일을 읽지마세요 이부분은 원한다면 예외처리해도됩니다.(저는 안함)

버퍼사이즈가 9999던 1이던 10000000이던 작동해야합니다.
libft사용금지
lseek()사용금지
전역변수 금지

#Instructions
Mandatory part를 구현했습니다.
bonus part는 구현하지 않았습니다.

main함수를 만들어 fd를 지정해주고
cc -Wall -Wextra -Werror -D BUFFER_SIZE=n <files> 로 실행하시면 됩니다.
valgrind --leak-check=full ./[실행파일명]으로 메모리 누수를 체크해주세요.

표준 입력을 시험하려면 fd를 0으로 바꾸고
printf "입력내용" | .[실행파일명]  로 실행하시면 됩니다.
컨트롤+d를 누르시면 종료됩니다.

#Resources
왜 이 과제에서 정적변수를 사용해야하는가? (read의 특성고려, lseek()금지)
return에 명령어 우겨넣기(라인 줄이는 잡기술)

위 정보들을 ai를 통해 학습했습니다.

#additions
들어온 문자열을 출력합니다

그중 %가 있으면 그 뒤의 문자가 무엇인지 검사하고 그에 맞는 출력방식을 골라 출력합니다
