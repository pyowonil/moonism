#pragma once

/*
# client가 가지고 있는 데이터 정보
1. 수배자 정보
	서버로부터 받음

하는일
1. 얼굴 detection
	tracking 정보 유지
	session 정보 유지

2. 얼굴 recognition(수배자 정보에서)
	만약 수배자 정보에 있으면 암호화 불필요
	없으면 암호화 필요

3. 암/복호화
	
**/

class Client
{
public:
	Client();
	~Client();
};

