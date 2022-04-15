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
	const int YOUNGER_BABY = 1, OLDER_BABY = 3, CHILD = 13, TEEN = 19, ADULT = 65;
	const int SAVE_TICKETING = 0, SAVE_BIRTH_ID = 1, SAVE_DAY = 2, SAVE_ORDER = 3, SAVE_PRICE = 4, SAVE_SPECIAL = 5;
	const int NO_ADVENTAGE = 1, ADVENTAGE_DISABLED = 2, ADVENTAGE_NATIONAL_MERIT = 3, ADVENTAGE_ARMY = 4, ADVENTAGE_PREGNANT = 5, ADVENTAGE_CHILDREN = 6;
	const int ONEDAY = 1;
	const int TICKET_ALL = 1;
	const int CONTINUE_TICKET = 1, EXIT = 2;
	int isExit = 0;
	int totalPrice = 0; // 주문 총액 
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
			int continueNumber;
			
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
			if (birth % 10000 <= (curr_month * 100 + curr_day)) {
				interAge++;
			}
			
			if (interAge < YOUNGER_BABY) {
				price = FREE;
			} else if (interAge < OLDER_BABY) {
				price = BABY;
			} else {
				if (ticket == TICKET_ALL) {
					if (day == ONEDAY) {
						if (interAge >= ADULT) { // 기타 우대 적용불가
							price = CHILD_1DAY_ALL;
						}
						switch(special){
							case NO_ADVENTAGE: 
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL;
								}
								break;
							case ADVENTAGE_DISABLED:
							case ADVENTAGE_NATIONAL_MERIT:
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL * 0.5;
								}
								break;
							case ADVENTAGE_ARMY:
								if (interAge < CHILD) {
									price = CHILD_ARMY_1DAY;
								} else if (interAge < TEEN) {
									price = TEEN_ARMY_1DAY;
								} else if (interAge < ADULT) {
									price = ADULT_ARMY_1DAY;
								}
								break;
							case ADVENTAGE_PREGNANT:
								price = ADULT_1DAY_ALL * 0.5;
								break;
							case ADVENTAGE_CHILDREN:
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
							case NO_ADVENTAGE: 
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL;
								}
								break;
							case ADVENTAGE_DISABLED:
							case ADVENTAGE_NATIONAL_MERIT:
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL * 0.5;
								}
								break;
							case ADVENTAGE_ARMY:
								if (interAge < CHILD) {
									price = CHILD_ARMY_AFTER4;
								} else if (interAge < TEEN) {
									price = TEEN_ARMY_AFTER4;
								} else if (interAge < ADULT) {
									price = ADULT_ARMY_AFTER4;
								}
								break;
							case ADVENTAGE_PREGNANT:
								price = ADULT_AFTER4_ALL * 0.5;
								break;
							case ADVENTAGE_CHILDREN:
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
					if (day == ONEDAY) {
						if (interAge >= ADULT) { // 기타 우대 적용불가
							price = CHILD_1DAY_PARK;
						}
						switch(special){
							case NO_ADVENTAGE:
							case ADVENTAGE_ARMY:
							case ADVENTAGE_PREGNANT:
							case ADVENTAGE_CHILDREN:
								if (interAge < CHILD) {
									price = CHILD_1DAY_PARK;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_PARK;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_PARK;
								}
								break;
							case ADVENTAGE_DISABLED:
							case ADVENTAGE_NATIONAL_MERIT:
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
							case NO_ADVENTAGE:
							case ADVENTAGE_ARMY:
							case ADVENTAGE_PREGNANT:
							case ADVENTAGE_CHILDREN:
								if (interAge < CHILD) {
									price = CHILD_AFTER4_PARK;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_PARK;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_PARK;
								}
								break;
							case ADVENTAGE_DISABLED:
							case ADVENTAGE_NATIONAL_MERIT:
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
			
			orderList[position][SAVE_TICKETING] = ticket; 
			orderList[position][SAVE_BIRTH_ID] = interAge;
			orderList[position][SAVE_DAY] = day;
			orderList[position][SAVE_ORDER] = order;
			orderList[position][SAVE_PRICE] = price;
			orderList[position][SAVE_SPECIAL] = special;
			
			printf("가격은 %d 원 입니다.\n감사합니다.\n", price);
			printf("계속 발권 하시겠습니까?\n1. 티켓 발권\n2. 종료\n");
			scanf("%d", &continueNumber);
			if (continueNumber == CONTINUE_TICKET) {
				position++;
			} else if (continueNumber == EXIT) {
				printf("티켓 발권을 종료합니다. 감사합니다.\n\n");
				printf("================== 롯데월드 ==================\n");
				for (int index = 0; index <= position; index++) {
					if (orderList[index][SAVE_TICKETING] == TICKET_ALL) {
						printf("종합이용권 ");
					} else {
						printf("파크이용권 ");
					}
					if (orderList[index][SAVE_BIRTH_ID] < YOUNGER_BABY)  {
						printf("12개월 미만 베이비 ");
					} else if (orderList[index][SAVE_BIRTH_ID] < OLDER_BABY) {
						printf("36개월 미만 베이비 ");
					} else if (orderList[index][SAVE_BIRTH_ID] < CHILD) {
						printf("어린이 ");
					} else if (orderList[index][SAVE_BIRTH_ID] < TEEN) {
						printf("청소년 ");
					} else if (orderList[index][SAVE_BIRTH_ID] < ADULT) {
						printf("어른 ");
					} else {
						printf("65세 이상 어른 ");
					}
					if (orderList[index][SAVE_DAY] == ONEDAY)  {
						printf("1Day ");
					} else {
						printf("After4 ");
					}
					printf("X     %d     ", orderList[index][SAVE_ORDER]);
					printf("%d원", orderList[index][SAVE_PRICE]);
					totalPrice += orderList[index][SAVE_PRICE];
					if (orderList[index][SAVE_SPECIAL] == NO_ADVENTAGE) {
						printf(" * 우대적용 없음\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_DISABLED) {
						printf(" * 장애인 우대적용\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_NATIONAL_MERIT) {
						printf(" * 국가유공자 우대적용\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_ARMY) {
						printf(" * 휴가장병 우대적용\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_PREGNANT) {
						printf(" * 임산부 우대적용\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_CHILDREN) {
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
