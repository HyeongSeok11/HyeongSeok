void transact() {
	int a, b;
	int h=0, k=0;
	int GetMoney, OutMoney;
	
	printf("\n고객님의 ID를 입력해주세요.\n");
	scanf("%d", &a);

	while( a != newacc.ID[h]) {
		
		if (h >= count) {
			printf("일치하는 ID가 없습니다.\n\n");
			menu();
		}
		else{
			h++;
		}
		
	}
	
	printf("\nID: %08d\n", newacc.ID[h]);
	printf("계좌 잔액: %d\n", newacc.AccountMoney[h]);
	
	int SelectMoney;
	printf("\n입금을 원하시면 1번을, 출금을 원하시면 2번을, 송금을 원하시면 3번, 취소는 4번을 입력해주세요.\n");
	scanf("%d", &SelectMoney);
	
	char GetName[20];
	int GetBirthday;
	
	swtich (SelectMoney) {
		
		case 1:
			printf("\n입금하실 금액을 입력해주세요.\n");
			scanf("%d", &Getmoney);
			newacc.AccountMoney[h] = newacc.AccountMoney[h] + Getmoney;
			printf("\n계좌 잔액: %d\n", newacc.AccountMoney[h]);
			break;
			
		case 2:
			if (newacc.AccountType[h] != "Current") {
				printf("\nSaving 계좌는 출금하실 수 없습니다.\n");
				menu();
			}
			else if (newacc.AccountType[h] == "Current") {
				printf("\n출금하실 금액을 입력해주세요.\n");
				scanf("%d", &OutMoney);
				newacc.AccountMoney[h] = newacc.AccountMoney[h] - OutMoney;
				printf("\n계좌 잔액: %d\n", newacc.AccountMoney[h]);				
			}
			break;
			
		case 3:
			if (newacc.AccountMoney[h] != "Current") {
				printf("\nSaving 계좌는 송금하실 수 없습니다.\n");
				menu();
			}
			else if (newacc.AccountType[h] == "Current") {
				printf("\n받는 사람의 이름을 적어주세요.\n");
				scanf("%s", GetName);
				printf("\n받는 사람의 생년월일을 적어주세요.\n");
				scanf("%d", &GetBirthday);
				
				while ((GetName == newacc.Name[k]) && (GetBirthday == newacc.Birthday[k]) ) {
					if (k >= count) {
			            printf("일치하는 사람이 없습니다.\n\n");
			            menu();
		                       }
		            else{
			            k++;
		                     }
				}
				
				int GiveNum;
				printf("\n받는 사람을 찾았습니다.\n %s %d가 맞습니까?\n 맞으면 1을, 아니면 2를 입력해주세요.\n", newacc.Name[k], newacc.Birthday);
				scanf("%d", &GiveNum);
				
				switch (GiveNum) {
					case 1:
						printf("\n보내실 금액을 입력해주세요.\n");
						scanf("%d", &OutMoney);
						newacc.AccountMoney[h]= newacc.AccountMoney[h] - OutMoney;
						newacc.AccountMoney[K]= newacc.AccountMoney[k] + OutMoney;
						printf("\n계좌 잔액: %d", &newacc.AccountMoney[h]);
						break;
						
					case 2:
						printf("\n다시 시도해주세요.\n");
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
			printf("\n오류입니다.\n");
			menu();
			break;
			
	}
	
}
