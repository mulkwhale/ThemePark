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
	int totalPrice = 0; // �ָ� �Ѿ� 
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
			if (birth % 10000 <= (curr_month * 100 + curr_day)){
				interAge++;
			}
			
			if (interAge < 1) {
				price = FREE;
			} else if (interAge < 3) {
				price = BABY;
			} else {
				if (ticket == 1) { // �����̿�� 
					if (day == 1) { // 1Day
						if (interAge >= ADULT) { // ��Ÿ ��� ����Ұ�
							price = CHILD_1DAY_ALL;
						}
						switch(special){
							case 1: // ���� 
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL;
								}
								break;
							case 2: // �����
							case 3: // ����������
								if (interAge < CHILD) {
									price = CHILD_1DAY_ALL * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_ALL * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_ALL * 0.5;
								}
								break;
							case 4: // �ް��庴 
								if (interAge < CHILD) {
									price = CHILD_ARMY_1DAY;
								} else if (interAge < TEEN) {
									price = TEEN_ARMY_1DAY;
								} else if (interAge < ADULT) {
									price = ADULT_ARMY_1DAY;
								}
								break;
							case 5: // �ӻ�� 
								price = ADULT_1DAY_ALL * 0.5;
								break;
							case 6: // �ٵ��� �ູī��
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
							case 1: // ���� 
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL;
								}
								break;
							case 2: // �����
							case 3: // ����������
								if (interAge < CHILD) {
									price = CHILD_AFTER4_ALL * 0.5;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_ALL * 0.5;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_ALL * 0.5;
								}
								break;
							case 4: // �ް��庴 
								if (interAge < CHILD) {
									price = CHILD_ARMY_AFTER4;
								} else if (interAge < TEEN) {
									price = TEEN_ARMY_AFTER4;
								} else if (interAge < ADULT) {
									price = ADULT_ARMY_AFTER4;
								}
								break;
							case 5: // �ӻ�� 
								price = ADULT_AFTER4_ALL * 0.5;
								break;
							case 6: // �ٵ��� �ູī��
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
					if (day == 1) { // 1Day
						if (interAge >= ADULT) { // ��Ÿ ��� ����Ұ�
							price = CHILD_1DAY_PARK;
						}
						switch(special){
							case 1: // ����
							case 4: // �ް��庴 
							case 5: // �ӻ�� 
							case 6: // �ٵ��� �ູī��
								if (interAge < CHILD) {
									price = CHILD_1DAY_PARK;
								} else if (interAge < TEEN) {
									price = TEEN_1DAY_PARK;
								} else if (interAge < ADULT) {
									price = ADULT_1DAY_PARK;
								}
								break;
							case 2: // �����
							case 3: // ����������
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
							case 1: // ����
							case 4: // �ް��庴 
							case 5: // �ӻ�� 
							case 6: // �ٵ��� �ູī��
								if (interAge < CHILD) {
									price = CHILD_AFTER4_PARK;
								} else if (interAge < TEEN) {
									price = TEEN_AFTER4_PARK;
								} else if (interAge < ADULT) {
									price = ADULT_AFTER4_PARK;
								}
								break;
							case 2: // �����
							case 3: // ����������
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
			
			orderList[position][0] = ticket; // ���� 
			orderList[position][1] = interAge; // ���ɱ��� 
			orderList[position][2] = day; // �ð���
			orderList[position][3] = order; // ���� 
			orderList[position][4] = price; // ���� 
			orderList[position][5] = special; // ������ 
			
			printf("������ %d �� �Դϴ�.\n�����մϴ�.\n", price);
			printf("��� �߱� �Ͻðڽ��ϱ�?\n1. Ƽ�� �߱�\n2. ����\n");
			scanf("%d", &continueNumber);
			if (continueNumber == 1) {
				position++;
			} else if (continueNumber == 2) {
				printf("Ƽ�� �߱��� �����մϴ�. �����մϴ�.\n\n");
				printf("================== �Ե����� ==================\n");
				for (int index = 0; index <= position; index++) {
					if (orderList[index][0] == 1) {
						printf("�����̿�� ");
					} else {
						printf("��ũ�̿�� ");
					}
					if (orderList[index][1] < 1)  {
						printf("12���� �̸� ���̺� ");
					} else if (orderList[index][1] < 3) {
						printf("36���� �̸� ���̺� ");
					} else if (orderList[index][1] < CHILD) {
						printf("��� ");
					} else if (orderList[index][1] < TEEN) {
						printf("û�ҳ� ");
					} else if (orderList[index][1] < ADULT) {
						printf("� ");
					} else {
						printf("65�� �̻� � ");
					}
					if (orderList[index][2] == 1)  {
						printf("1Day ");
					} else {
						printf("After4 ");
					}
					printf("X     %d     ", orderList[index][3]);
					printf("%d��", orderList[index][4]);
					totalPrice += orderList[index][4];
					if (orderList[index][5] == 1) {
						printf(" * ������� ����\n");
					} else if (orderList[index][5] == 2) {
						printf(" * ����� �������\n");
					} else if (orderList[index][5] == 3) {
						printf(" * ���������� �������\n");
					} else if (orderList[index][5] == 4) {
						printf(" * �ް��庴 �������\n");
					} else if (orderList[index][5] == 5) {
						printf(" * �ӻ�� �������\n");
					} else if (orderList[index][5] == 6) {
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
