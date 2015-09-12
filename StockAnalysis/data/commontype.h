#ifndef COMMONTYPE
#define COMMONTYPE

typedef enum { ALL=0, KOSPI=1, KOSDAQ=2, SECTOR=3, MARKET_TYPE_NONE}MARKET_TYPE ;

typedef enum {
                INDIVISUAL                  = 0,	//개인
                FORCES 						= 1,    //세력합
                REGISTERED_FOREIGNER        = 2,	//외국인
                INSTITUTION                 = 3,    //기관
                PEF                         = 4,	//사모펀드
                INVESTMENT_C                = 5,	//금융투자(증권)
                INSURANCE                   = 6,	//보험
                INVESTMENT_T                = 7,	//투자신탁(투신)
                BANK                        = 8,    //은행
                ALLFINANZ                   = 9,	//종합금융(종금)
                NPF                         = 10,   //연기금
                CORP                        = 11,	//기타법인
                NON_REGISTERED_FOREIGNER    = 12, 	//내외국인
                NATIONAL                    = 13,	//국가외
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

