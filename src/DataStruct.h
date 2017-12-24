typedef struct way
{
	int locationId;//ȥ���ص�Ǳ�
	struct way* nextway;//�˵ص���һ��·
	int info;//��·���ȼǵ���ʱ�䣨�֣�
	int* ambulances;//int������ÿ���Ȼ����ھȻ��������е�λ�ã���ʾ������������·��
}way; //��·

typedef struct location
{
	char* location;//�ص�����
	int locationId;//�ص��ţ�Ψһ��ʶ
	int type; //�ص�����{1��ҽԺ��0�����ȵ㣻}
	way* ways;//way�ĵ������洢��õص�ֱ�������ĵص�ĵ�·��Ϣ
	int amount;//�˵ؼ��ȳ�����������Ҫ����ҽԺ
	int* ambulance;//int������ÿ���Ȼ����ھȻ��������е�λ�ã���ʾ������������ص�
	int* patients;//int������ÿ�������ڲ��˼����е�λ�ã���ʾ�������������ص�
}location;//�ص�

typedef struct
{
	int ambulanceld; //�Ȼ���Ψһ��ʶ�������涨4λ����
	int status;//�Ȼ���״̬{0��������1�����ȣ�2����Ժ��}
	int time;//���м����ӵ���ָ���ص�
	int destination;//Ŀ�ĵ���Ŀ�ĵؼ����е�λ��
	int patient;//�����ڲ��˼����е�
}ambulance;//�Ȼ���

typedef struct
{
	int patientld;//����Ψһ��ʶ�������涨4λ����
	int status;//�Ȼ���״̬{0�����ɳ���1�����ӣ�2����Ժ��}
	int located;//��������λ��
}patient;//����

location* locations[100];//�㼯��
int helpPlace[100]; //���ȵ㼯�� 
int hospital[100];//ҽԺ�㼯�� 
ambulance ambulances[100];//�Ȼ�������
int actAmbulances[100];//��Ȼ�������
patient patients[100];//���˼�¼
patient waitPatients[100];//�������˼�¼
