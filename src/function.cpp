
#include<stdio.h>
#include<string.h>
#include<malloc.h>
#include "DataStruct.h"




int locationAmount = 0 ;
int aNumber = 0, bNumber = 0;
int a[100] = {3,6,10,5,12,5,12,10};
char* b[100] = {"hospital","a","b","hospital","b","hospital","a","a","b","a","hospital","b","a","b","hospital"};
int c, d;//���ж�������ͻ�


/**
*���ӵ�ͼ�еĵص� (�ص����ƣ��ص����ͣ��ص��ţ�����ʡ�ԣ�ĿǰӦ��ֻ���ļ���дʱ�õ���Ӧ���⸲�������)
*��ʼ���ص� 
*�ɹ����� �ص�λ�ã����ɹ�����-1��-2 
*/
int addLocation(char* locationName,int type,int locationId = -1){ 
	location* a;
	a = (location *)malloc(sizeof(location));//����洢�ռ� 
	int b[10] = {0};
	int c[10] = {0};
	if(!locationName) 
		return -1;
	if(type!=1&&type!=0)
		return -2;
	
	a->location = locationName;
	
	a->type = type;

	way* way_head = (way*)malloc(sizeof(way));
	way_head->nextway = NULL;//������ͷ 
	
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
		locations[locationId] = a;//δ�����Ǵ���Ӧ��֤���ݰ�ȫ 
		locationAmount++;
		return locationId; 
	}
	
}

/**
*�������ӵ�·������ȫ��������ʹ�� 
*����ʹ�� addWay���� 
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
			if(ways->locationId == location_b) {//���ǵ�· 
				ways->info = time;
				return; 
			}
			ways = ways->nextway;	
		}
		ways->nextway = wayab;
		return;
	}
/**
*���ӵ�ͼ�еĵ�·
*��ʼ����· 
*�ɹ�����1�����ɹ�����-1��-2 
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




void Create()                                                    //������ͼ
{
	int a = addLocation("ҽԺ",1);
	int b = addLocation("ѧУ",0);
	int c = addLocation("ҹ�ܻ�",0);
	
	addWay(a,b,5);
	addWay(a,c,1); 
	addWay(b,c,10); 
	
}

void DispAdj()                                            //��ʾ�ڽӱ�
{
	int i;
	way *p;
	for (i = 0; i < locationAmount; i++)
	{
		p = locations[i]->ways;
		while (p->nextway)
		{
			p=p->nextway;
			printf("%8s���Ե���", locations[i]->location);
			printf("%8s,����Ϊ%d\n", locations[p->locationId]->location, p->info);
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


