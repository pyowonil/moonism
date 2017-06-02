#pragma once

/*
# server가 가지고 있는 데이터 정보
1. 수배자 정보
	name;{images}
2. 정상인 정보
	id;(pk,sk);{images}
	
client initialization시: 수배자 정보는 client에게 줄 정보임
client로부터 받은 얼굴 이미지를 정상인 정보에서 검색(identification)
	만약 찾으면 (pk,id) 반환 (업데이트 추후 추가 가능)
	못찾으면 새로운 정상인 정보로 등록(id;(pk,sk),{방금 이미지s})하여 (pk,id) 반환
**/

class Server
{
public:
	Server();
	~Server();
};

