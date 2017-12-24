
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "DataStruct.h"




int locationAmount = 0 ;
int aNumber = 0, bNumber = 0;
int a[100] = {3,6,10,5,12,5,12,10};
char* b[100] = {"hospital","a","b","hospital","b","hospital","a","a","b","a","hospital","b","a","b","hospital"};
int c, d;//共有多少跳点和弧


/**
*增加地图中的地点 (地点名称，地点类型，地点编号（可以省略，目前应该只有文件读写时用到，应避免覆盖情况）)
*初始化地点 
*成功返回 地点位置，不成功返回-1或-2 
*/
int addLocation(char* locationName,int type,int locationId = -1){ 
	location* a;
	a = (location *)malloc(sizeof(location));//申请存储空间 
	int b[10] = {0};
	int c[10] = {0};
	if(!locationName) 
		return -1;
	if(type!=1&&type!=0)
		return -2;
	
	a->location = locationName;
	
	a->type = type;

	way* way_head = (way*)malloc(sizeof(way));
	way_head->nextway = NULL;//单链表头 
	
	a->ways = way_head;
	a->amount = 0;
	a->ambulance = b;
	a->patients = c;
	
	if(locationId == -1){
		a->locationId = locationAmount;
		locations[locationAmount++] = a;

		return locationAmount-1; 
	}else{
		a->locationId = locationId;
		locations[locationId] = a;//未做覆盖处理，应保证数据安全 
		locationAmount++;
		return locationId; 
	}
	
}

/**
*单向增加道路，不安全，不建议使用 
*建议使用 addWay函数 
*/
inline void addOneWay(int location_a, int location_b,const int time){
		
		location* a = locations[location_a];

		int ama[10]={0};
		way* wayab ;
		wayab = (way*)malloc(sizeof(way));
		wayab->locationId = location_b;
		wayab->info = time;
		wayab->nextway = NULL;
		wayab->ambulances = ama;

		way* ways = a->ways;
		while(ways->nextway){
			if(ways->locationId == location_b) {//覆盖道路 
				ways->info = time;
				return; 
			}
			ways = ways->nextway;	
		}
		ways->nextway = wayab;
		return;
	}
/**
*增加地图中的道路
*初始化道路 
*成功返回1，不成功返回-1或-2 
*/
int addWay(int location_a, int location_b,const int time){ 
	if(location_b==location_a&&location_a<0&&location_a>=locationAmount&&location_b<0&&location_b>=locationAmount)
		return -1;
	if(time<1){
		return -2; 
	}	
	addOneWay(location_a,location_b,time);
	addOneWay(location_b,location_a,time);
			
	return 1; 
}




void Create()                                                    //建立地图
{
	int a = addLocation("医院",1);
	int b = addLocation("学校",0);
	int c = addLocation("夜总会",0);
	
	addWay(a,b,5);
	addWay(a,c,1); 
	addWay(b,c,10); 
	
}

void DispAdj()                                            //显示邻接表
{
	int i;
	way *p;
	for (i = 0; i < locationAmount; i++)
	{
		p = locations[i]->ways;
		while (p->nextway)
		{
			p=p->nextway;
			printf("%8s可以到达", locations[i]->location);
			printf("%8s,距离为%d\n", locations[p->locationId]->location, p->info);
			p = p->nextway;
		}
		printf("\n");
	}
}

int main()
{


	Create();
	DispAdj();
    return 0;
}


