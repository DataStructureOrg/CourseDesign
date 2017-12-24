typedef struct way
{
	int locationId;//去往地点角标
	struct way* nextway;//此地的下一条路
	int info;//道路长度记单程时间（分）
	int* ambulances;//int数组存放每辆救护车在救护车集合中的位置，表示这辆车在这条路上
}way; //道路

typedef struct location
{
	char* location;//地点名称
	int locationId;//地点标号，唯一标识
	int type; //地点类型{1：医院；0：呼救点；}
	way* ways;//way的单链表，存储与该地点直接相连的地点的道路信息
	int amount;//此地急救车的数量，主要用于医院
	int* ambulance;//int数组存放每辆救护车在救护车集合中的位置，表示这辆车在这个地点
	int* patients;//int数组存放每个病人在病人集合中的位置，表示这个病人在这个地点
}location;//地点

typedef struct
{
	int ambulanceld; //救护车唯一标识（初步规定4位数）
	int status;//救护车状态{0：待命；1：往救；2：送院；}
	int time;//还有几分钟到达指定地点
	int destination;//目的地在目的地集合中的位置
	int patient;//病人在病人集合中的
}ambulance;//救护车

typedef struct
{
	int patientld;//病人唯一标识（初步规定4位数）
	int status;//救护车状态{0：待派车；1：带接；2：送院；}
	int located;//病人所在位置
}patient;//病人

location* locations[100];//点集合
int helpPlace[100]; //呼救点集合 
int hospital[100];//医院点集合 
ambulance ambulances[100];//救护车集合
int actAmbulances[100];//活动救护车集合
patient patients[100];//病人记录
patient waitPatients[100];//待处理病人记录
