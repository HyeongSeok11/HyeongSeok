void transact() {
	int a, b;
	int h=0, k=0;
	int GetMoney, OutMoney;
	
	printf("\n������ ID�� �Է����ּ���.\n");
	scanf("%d", &a);

	while( a != newacc.ID[h]) {
		
		if (h >= count) {
			printf("��ġ�ϴ� ID�� �����ϴ�.\n\n");
			menu();
		}
		else{
			h++;
		}
		
	}
	
	printf("\nID: %08d\n", newacc.ID[h]);
	printf("���� �ܾ�: %d\n", newacc.AccountMoney[h]);
	
	int SelectMoney;
	printf("\n�Ա��� ���Ͻø� 1����, ����� ���Ͻø� 2����, �۱��� ���Ͻø� 3��, ��Ҵ� 4���� �Է����ּ���.\n");
	scanf("%d", &SelectMoney);
	
	char GetName[20];
	int GetBirthday;
	
	swtich (SelectMoney) {
		
		case 1:
			printf("\n�Ա��Ͻ� �ݾ��� �Է����ּ���.\n");
			scanf("%d", &Getmoney);
			newacc.AccountMoney[h] = newacc.AccountMoney[h] + Getmoney;
			printf("\n���� �ܾ�: %d\n", newacc.AccountMoney[h]);
			break;
			
		case 2:
			if (newacc.AccountType[h] != "Current") {
				printf("\nSaving ���´� ����Ͻ� �� �����ϴ�.\n");
				menu();
			}
			else if (newacc.AccountType[h] == "Current") {
				printf("\n����Ͻ� �ݾ��� �Է����ּ���.\n");
				scanf("%d", &OutMoney);
				newacc.AccountMoney[h] = newacc.AccountMoney[h] - OutMoney;
				printf("\n���� �ܾ�: %d\n", newacc.AccountMoney[h]);				
			}
			break;
			
		case 3:
			if (newacc.AccountMoney[h] != "Current") {
				printf("\nSaving ���´� �۱��Ͻ� �� �����ϴ�.\n");
				menu();
			}
			else if (newacc.AccountType[h] == "Current") {
				printf("\n�޴� ����� �̸��� �����ּ���.\n");
				scanf("%s", GetName);
				printf("\n�޴� ����� ��������� �����ּ���.\n");
				scanf("%d", &GetBirthday);
				
				while ((GetName == newacc.Name[k]) && (GetBirthday == newacc.Birthday[k]) ) {
					if (k >= count) {
			            printf("��ġ�ϴ� ����� �����ϴ�.\n\n");
			            menu();
		                       }
		            else{
			            k++;
		                     }
				}
				
				int GiveNum;
				printf("\n�޴� ����� ã�ҽ��ϴ�.\n %s %d�� �½��ϱ�?\n ������ 1��, �ƴϸ� 2�� �Է����ּ���.\n", newacc.Name[k], newacc.Birthday);
				scanf("%d", &GiveNum);
				
				switch (GiveNum) {
					case 1:
						printf("\n������ �ݾ��� �Է����ּ���.\n");
						scanf("%d", &OutMoney);
						newacc.AccountMoney[h]= newacc.AccountMoney[h] - OutMoney;
						newacc.AccountMoney[K]= newacc.AccountMoney[k] + OutMoney;
						printf("\n���� �ܾ�: %d", &newacc.AccountMoney[h]);
						break;
						
					case 2:
						printf("\n�ٽ� �õ����ּ���.\n");
						menu();
						break;
					
					default:
						menu();
						break;
				}
			}
			break;
		
		case 4:
			menu();
			break;
					
		default:
			printf("\n�����Դϴ�.\n");
			menu();
			break;
			
	}
	
}
