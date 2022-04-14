#include<stdio.h>
#include<time.h>
int main(){
	const int BABY = 15000, FREE = 0;
	const int ADULT_1DAY_ALL = 62000, TEEN_1DAY_ALL = 54000, CHILD_1DAY_ALL = 47000;
	const int ADULT_AFTER4_ALL = 50000, TEEN_AFTER4_ALL = 43000, CHILD_AFTER4_ALL = 36000;
	const int ADULT_1DAY_PARK = 59000, TEEN_1DAY_PARK = 52000, CHILD_1DAY_PARK = 46000;
	const int ADULT_AFTER4_PARK = 47000, TEEN_AFTER4_PARK = 41000, CHILD_AFTER4_PARK = 35000;
	const int ADULT_ARMY_1DAY = 30000, TEEN_ARMY_1DAY = 26500, CHILD_ARMY_1DAY = 24000;
	const int ADULT_ARMY_AFTER4 = 24500, TEEN_ARMY_AFTER4 = 21500, CHILD_ARMY_AFTER4 = 18500;
	const int CHILD = 13, TEEN = 19, ADULT = 65;
	int isExit = 0;
	int totalPrice = 0; // 주몬 총액 
	int position = 0; // 주문 내역 배열 탐색용
	int orderList[100][6] = { 0 }; // 주문 내역 저장
	
	do{
		while(true){
			int ticket;
			int birth, id;
			int day;
			int order;
			int special;
			int price;
			
			int interAge = 0;
			int age;
			
			int curr_year;
			int curr_month;
			int curr_day;
			
			struct tm *curr_tm;
			time_t curr_time = time(NULL);
			
			curr_tm = localtime(&curr_time);
			
			printf("권종을 선택하세요.\n1. 종합이용권\n2. 파크이용권\n");
			scanf("%d", &ticket);
			printf("주민번호를 입력하세요\n");
			scanf("%6d%7d", &birth, &id);
			printf("시간대를 선택하세요\n1. 1Day\n2. After4\n");
			scanf("%d", &day);
			printf("몇 개를 주문하시겠습니까? (최대 10개)\n");
			scanf("%d", &order);
			printf("우대사항을 선택하세요.\n1. 없음 (나이 우대는 자동처리)\n2. 장애인\n3. 국가유공자\n4. 휴가장병\n5. 임산부\n6. 다둥이 행복카드\n");
			scanf("%d", &special);
			
			// 만나이 계산
			curr_year = curr_tm -> tm_year + 1900;
			curr_month = curr_tm -> tm_mon + 1;
			curr_day = curr_tm -> tm_mday;
			
			age = id / 1000000;
			
			if (age < 3) {
				interAge = curr_year - (1900 + birth / 10000) - 1;
			} else {
				interAge = curr_year - (2000 + birth / 10000) - 1;
			}
			if (birth % 10000 <= (curr_month * 100 + curr_day)){
				interAge++;
			}
			
			if (interAge < 1) {
				price = FREE;
			} else if (interAge < 3) {
				price = BABY;
			} else {
				if (ticket == 1) { // 종합이용권 
					if (day == 1) { // 1Day
						if (interAge >= ADULT) { // 기타 우대 적용불가
							price = CHILD_1DAY_ALL;
						}
						switch(special){
							case 1: // 없음 
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL;
								}
								break;
							case 2: // 장애인
							case 3: // 국가유공자
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL * 0.5;
								}
								break;
							case 4: // 휴가장병 
								if (interAge < CHILD) {
									price = CHILD_ARMY_1DAY;
								} else if (interAge < TEEN) {
									price = TEEN_ARMY_1DAY;
								} else if (interAge < ADULT) {
									price = ADULT_ARMY_1DAY;
								}
								break;
							case 5: // 임산부 
								price = ADULT_1DAY_ALL * 0.5;
								break;
							case 6: // 다둥이 행복카드
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL * 0.7;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL * 0.7;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL * 0.7;
								}
								break;
						}
					} else { // After4
						if (interAge >= ADULT) { // 기타 우대 적용불가
							price = CHILD_AFTER4_ALL;
						}
						switch(special){
							case 1: // 없음 
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL;
								}
								break;
							case 2: // 장애인
							case 3: // 국가유공자
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL * 0.5;
								}
								break;
							case 4: // 휴가장병 
								if (interAge < CHILD) {
									price = CHILD_ARMY_AFTER4;
								} else if (interAge < TEEN) {
									price = TEEN_ARMY_AFTER4;
								} else if (interAge < ADULT) {
									price = ADULT_ARMY_AFTER4;
								}
								break;
							case 5: // 임산부 
								price = ADULT_AFTER4_ALL * 0.5;
								break;
							case 6: // 다둥이 행복카드
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL * 0.7;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL * 0.7;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL * 0.7;
								}
								break;
						}
					}
				} else { // 파크이용권 
					if (day == 1) { // 1Day
						if (interAge >= ADULT) { // 기타 우대 적용불가
							price = CHILD_1DAY_PARK;
						}
						switch(special){
							case 1: // 없음
							case 4: // 휴가장병 
							case 5: // 임산부 
							case 6: // 다둥이 행복카드
								if (interAge < CHILD) {
									price = CHILD_1DAY_PARK;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_PARK;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_PARK;
								}
								break;
							case 2: // 장애인
							case 3: // 국가유공자
								if (interAge < CHILD) {
									price = CHILD_1DAY_PARK * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_PARK * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_PARK * 0.5;
								}
								break;
						}
					} else { // After4
						if (interAge >= ADULT) { // 기타 우대 적용불가
							price = CHILD_AFTER4_PARK;
						}
						switch(special){
							case 1: // 없음
							case 4: // 휴가장병 
							case 5: // 임산부 
							case 6: // 다둥이 행복카드
								if (interAge < CHILD) {
									price = CHILD_AFTER4_PARK;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_PARK;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_PARK;
								}
								break;
							case 2: // 장애인
							case 3: // 국가유공자
								if (interAge < CHILD) {
									price = CHILD_AFTER4_PARK * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_PARK * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_PARK * 0.5;
								}
								break;
						}
					}
				}
			}
			price *= order;
			
			orderList[position][0] = ticket; // 권종 
			orderList[position][1] = interAge; // 연령구분 
			orderList[position][2] = day; // 시간대
			orderList[position][3] = order; // 수량 
			orderList[position][4] = price; // 가격 
			orderList[position][5] = special; // 우대사항 
			
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
			printf("계속 발권 하시겠습니까?\n1. 티켓 발권\n2. 종료\n");
			scanf("%d", &continueNumber);
			if (continueNumber == 1) {
				position++;
			} else if (continueNumber == 2) {
				printf("티켓 발권을 종료합니다. 감사합니다.\n\n");
				printf("================== 롯데월드 ==================\n");
				for (int index = 0; index <= position; index++) {
					if (orderList[index][0] == 1) {
						printf("종합이용권 ");
					} else {
						printf("파크이용권 ");
					}
					if (orderList[index][1] < 1)  {
						printf("12개월 미만 베이비 ");
					} else if (orderList[index][1] < 3) {
						printf("36개월 미만 베이비 ");
					} else if (orderList[index][1] < CHILD) {
						printf("어린이 ");
					} else if (orderList[index][1] < TEEN) {
						printf("청소년 ");
					} else if (orderList[index][1] < ADULT) {
						printf("어른 ");
					} else {
						printf("65세 이상 어른 ");
					}
					if (orderList[index][2] == 1)  {
						printf("1Day ");
					} else {
						printf("After4 ");
					}
					printf("X     %d     ", orderList[index][3]);
					printf("%d원", orderList[index][4]);
					totalPrice += orderList[index][4];
					if (orderList[index][5] == 1) {
						printf(" * 우대적용 없음\n");
					} else if (orderList[index][5] == 2) {
						printf(" * 장애인 우대적용\n");
					} else if (orderList[index][5] == 3) {
						printf(" * 국가유공자 우대적용\n");
					} else if (orderList[index][5] == 4) {
						printf(" * 휴가장병 우대적용\n");
					} else if (orderList[index][5] == 5) {
						printf(" * 임산부 우대적용\n");
					} else if (orderList[index][5] == 6) {
						printf(" * 다둥이 행복카드 우대적용\n");
					} 
				}
				printf("\n입장료 총액은 %d원 입니다.\n", totalPrice);
				printf("==============================================\n\n");
				break;
			}
		}
		printf("계속 진행(1: 새로운 주문, 2: 프로그램 종료) : ");
		scanf("%d", &isExit);
		
		position = 0;
		totalPrice = 0;
	}while(isExit == 1);
	
	return 0;
}
