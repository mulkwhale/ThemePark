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
	int totalPrice = 0; // �ֹ� �Ѿ� 
	int position = 0; // �ֹ� ���� �迭 Ž����
	int orderList[100][6] = { 0 }; // �ֹ� ���� ����
	
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
			
			printf("������ �����ϼ���.\n1. �����̿��\n2. ��ũ�̿��\n");
			scanf("%d", &ticket);
			printf("�ֹι�ȣ�� �Է��ϼ���\n");
			scanf("%6d%7d", &birth, &id);
			printf("�ð��븦 �����ϼ���\n1. 1Day\n2. After4\n");
			scanf("%d", &day);
			printf("�� ���� �ֹ��Ͻðڽ��ϱ�? (�ִ� 10��)\n");
			scanf("%d", &order);
			printf("�������� �����ϼ���.\n1. ���� (���� ���� �ڵ�ó��)\n2. �����\n3. ����������\n4. �ް��庴\n5. �ӻ��\n6. �ٵ��� �ູī��\n");
			scanf("%d", &special);
			
			// ������ ���
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
						if (interAge >= ADULT) { // ��Ÿ ��� ����Ұ�
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
						if (interAge >= ADULT) { // ��Ÿ ��� ����Ұ�
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
				} else { // ��ũ�̿�� 
					if (day == ONEDAY) {
						if (interAge >= ADULT) { // ��Ÿ ��� ����Ұ�
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
						if (interAge >= ADULT) { // ��Ÿ ��� ����Ұ�
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
			
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
			printf("��� �߱� �Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����\n");
			scanf("%d", &continueNumber);
			if (continueNumber == CONTINUE_TICKET) {
				position++;
			} else if (continueNumber == EXIT) {
				printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n\n");
				printf("================== �Ե����� ==================\n");
				for (int index = 0; index <= position; index++) {
					if (orderList[index][SAVE_TICKETING] == TICKET_ALL) {
						printf("�����̿�� ");
					} else {
						printf("��ũ�̿�� ");
					}
					if (orderList[index][SAVE_BIRTH_ID] < YOUNGER_BABY)  {
						printf("12���� �̸� ���̺� ");
					} else if (orderList[index][SAVE_BIRTH_ID] < OLDER_BABY) {
						printf("36���� �̸� ���̺� ");
					} else if (orderList[index][SAVE_BIRTH_ID] < CHILD) {
						printf("��� ");
					} else if (orderList[index][SAVE_BIRTH_ID] < TEEN) {
						printf("û�ҳ� ");
					} else if (orderList[index][SAVE_BIRTH_ID] < ADULT) {
						printf("� ");
					} else {
						printf("65�� �̻� � ");
					}
					if (orderList[index][SAVE_DAY] == ONEDAY)  {
						printf("1Day ");
					} else {
						printf("After4 ");
					}
					printf("X     %d     ", orderList[index][SAVE_ORDER]);
					printf("%d��", orderList[index][SAVE_PRICE]);
					totalPrice += orderList[index][SAVE_PRICE];
					if (orderList[index][SAVE_SPECIAL] == NO_ADVENTAGE) {
						printf(" * ������� ����\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_DISABLED) {
						printf(" * ����� �������\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_NATIONAL_MERIT) {
						printf(" * ���������� �������\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_ARMY) {
						printf(" * �ް��庴 �������\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_PREGNANT) {
						printf(" * �ӻ�� �������\n");
					} else if (orderList[index][SAVE_SPECIAL] == ADVENTAGE_CHILDREN) {
						printf(" * �ٵ��� �ູī�� �������\n");
					} 
				}
				printf("\n����� �Ѿ��� %d�� �Դϴ�.\n", totalPrice);
				printf("==============================================\n\n");
				break;
			}
		}
		printf("��� ����(1: ���ο� �ֹ�, 2: ���α׷� ����) : ");
		scanf("%d", &isExit);
		
		position = 0;
		totalPrice = 0;
	}while(isExit == 1);
	
	return 0;
}
