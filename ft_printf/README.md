*This project has been created as part of the 42 curriculum by <cjung>*

#Description
이번 과제는 ft_printf 만들기입니다.
ft_printf는 printf의 기능들을 모방하는 함수입니다.
printf의 버퍼 관리를 구현해선 안됩니다.
라이브러리를 만들 때 ar 커맨드를 사용해야 합니다.
libftprintf.a는 repository의 root에 만들어져야합니다.
헤더는 ft_printf.h로 이름짓고 ft_printf()의 원형이 포함되어야 합니다.

#Instructions
Mandatory part(cspdiuxX%)를 구현했습니다.

c = 단일 문자를 출력합니다.
s = 문자열을 출력합니다.
p = 포인터 주소를 16진수로 변환해 출력합니다.
d = 10진수 정수를 출력합니다.
i = 10진수 정수를 출력합니다.
u = unsigned 10진수 정수를 출력합니다.
x = 소문자 알파벳을 활용해 16진수 정수를 출력합니다.
X = 대문자 알파벳을 활용해 16진수 정수를 출력합니다.
% = %를 출력합니다.

bonus part는 구현되지 않았습니다.

printf와 같은 방식으로 사용하시면 됩니다.

오류라고 판단될 만한 입력을 넣으면 -1을 반환합니다.

#Resources
가변인자 개념
왜 10진수 정수 출력 플래그가 두개인지
특정 케이스에서의 printf의 출력값
write함수 실패원리
각 플래그들의 의미

위 정보들을 ai를 통해 학습했습니다.

#additions
입력값이 들어오면 
