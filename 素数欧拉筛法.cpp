const ll maxn=100000001;
ll prime[maxn];      //���Ǹ�������
bool sf[maxn];        //�ж�������ǲ���������sf[i]�е�i�Ǵ�1��maxn����
void sushu()
{         //���� ŷ��ɸ����
    ll num=0;        //num ������ɸ���ڼ�������
    memset(sf,true,sizeof(sf));
	sf[1] = false;
    sf[0] = false;  //1 0 ���� 
    for(int i = 2;i <= maxn; i ++)
	{          //���ö��1~maxn
        if(sf[i]) prime[++num] = i;      //����������ͼ���������
        for(int j = 1;j <= num;j ++)
		{       //�ڲ�ö��num���ڵ�����
            if(i * prime[j] > maxn) break; //ɸ�����
            sf[i * prime[j]] = false;      //ɸ��...
            if(i % prime[j] == 0) break;   //�����ظ�ɸ
        }
    } 
}

