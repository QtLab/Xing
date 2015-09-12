#ifndef COMMONTYPE
#define COMMONTYPE

typedef enum { ALL=0, KOSPI=1, KOSDAQ=2, SECTOR=3, MARKET_TYPE_NONE}MARKET_TYPE ;

typedef enum {
                INDIVISUAL                  = 0,	//����
                FORCES 						= 1,    //������
                REGISTERED_FOREIGNER        = 2,	//�ܱ���
                INSTITUTION                 = 3,    //���
                PEF                         = 4,	//����ݵ�
                INVESTMENT_C                = 5,	//��������(����)
                INSURANCE                   = 6,	//����
                INVESTMENT_T                = 7,	//���ڽ�Ź(����)
                BANK                        = 8,    //����
                ALLFINANZ                   = 9,	//���ձ���(����)
                NPF                         = 10,   //�����
                CORP                        = 11,	//��Ÿ����
                NON_REGISTERED_FOREIGNER    = 12, 	//���ܱ���
                NATIONAL                    = 13,	//������
                INVESTOR_NONE						= 14
             } INVESTORS;
#define NUM_OF_INVESTORS static_cast<int>(INVESTOR_NONE)
#define PEF_COLUMN "amt0000"
#define INVESTMENT_C_COLUMN "amt0001"
#define INSURANCE_COLUMN "amt0002"
#define INVESTMENT_T_COLUMN "amt0003"
#define BANK_COLUMN "amt0004"
#define ALLFINANZ_COLUMN "amt0005"
#define NPF_COLUMN "amt0006"
#define CORP_COLUMN "amt0007"
#define INDIVISUAL_COLUMN "amt0008"
#define REGISTERED_FOREIGNER_COLUMN "amt0009"
#define NON_REGISTERED_FOREIGNER_COLUMN "amt0010"
#define NATIONAL_COLUMN "amt0011"
#define INSTITUTION_COLUMN "amt0018"
#define FORCES_COLUMN "(amt0000+amt0001+amt0002+amt0003+amt0004+amt0005+amt0006+amt0007+amt0009+amt0011)"
#endif // COMMONTYPE

