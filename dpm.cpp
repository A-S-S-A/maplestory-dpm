#include <iostream>
#include <algorithm>
#include <vector>
#include <cmath>

using namespace std;
//buf를 vector 바꿀지 고려
int mer=5,coolgam=0,simulation_time=15000;
class buff
{
public:
	buff();
	~buff();
	void input(int id);
	friend bool operator < (const buff& buf, const buff& buf2)
	{
		return buf.cooltime > buf2.cooltime; //테스트 필요
	}
	int buf_id;
	int cooltime;
	int delay;
	int damage;
	int final_damage;
	int stat_per;
	int final_attack;
	//int deal;
	vector<int> schedule;
	int zisok;
	int final_cool;
	int atk_id;
	int last_attack;
	vector <int> final;
	int cri_damage;
	int stat;
	int attack;
	int attack_per;
	long long dpm;
	int use;
	int final_time;
	int direct;
	double inc_gauge;
	double req_gauge;
private:
};

buff::buff()
{
	dpm=0;
	use=0;
}

buff::~buff()
{

}


void buff::input(int id)
{
	buf_id = id;
	cin >> cooltime >> delay >> damage >> final_damage >> stat_per >> zisok >> cri_damage >> stat >> attack >> attack_per >>  final_attack >> final_cool >> atk_id >> final_time >> direct >> req_gauge >> inc_gauge;
	if (cooltime == 0) 
	{
		cooltime = 120000;
		zisok=simulation_time;
		return;
	}
	cooltime = cooltime * (100-mer)/100;
	if (cooltime <= 10000)
	{
		cooltime = cooltime * (100-5*coolgam) / 100;
	}
	else if (cooltime - coolgam * 1000 <= 10000)
	{
		cooltime = (100000-5*(1000*coolgam-(cooltime-10000))) /10;
	}
	else cooltime -= coolgam*1000;
	if (final_cool==0) return;
	final_cool = final_cool * (100-mer)/100;
	if (final_cool <= 10000)
	{
		final_cool = final_cool * (100-5*coolgam) / 100;
	}
	else if (final_cool - coolgam * 1000 <= 10000)
	{
		final_cool = (100000-5*(1000*coolgam-(final_cool-10000))) /10;
	}
	else final_cool -= coolgam*1000;
}

class attack
{
public:
	attack();
	~attack();
	void input(int id);
	friend bool operator < (const attack& atk,const attack& atk2)
	{
		if (atk.summon_zisok == simulation_time) return false;
		int atkper_damage = atk.per_damage;
		int atk2per_damage = atk2.per_damage;
		int atkdelay = atk.delay;
		int atk2delay = atk2.delay;
		if (atk.summon_delay) 
		{
			atkper_damage += (atk.summon_zisok/atk.summon_delay)*atk.summon_per_damage / 2;
			atkdelay = atk.summon_delay;
		}
		if (atk2.summon_delay)
		{
			 atk2per_damage += (atk2.summon_zisok/atk2.summon_delay)*atk2.summon_per_damage / 2;
			 atk2delay = atk2.summon_delay;
		}
		if (atk.zisok) atkdelay = 1000;
		if (atk2.zisok) atk2delay = 1000;
		bool result=0;
		return atkper_damage/atkdelay > atk2per_damage/atk2delay;
		//return atk.per_damage/((atk.zisok > 0) ? atk.delay : 1000) > atk2.per_damage/((atk2.zisok > 0) ? atk2.delay:1000);
	}
	int atk_id;
	int cooltime;
	int delay;
	int summon_delay;
	int summon_per_damage;
	int summon_zisok;
	int per_damage;
	//int final_damage;
	//9int deal;
	vector<int> schedule;
	int zisok;
	long long dpm;
	int direct;
	int use;
	double req_gauge;
	double inc_gauge;
private:

};

attack::attack()
{
	dpm = 0;
}

attack::~attack()
{
}

void attack::input(int id)
{
	atk_id = id;
	use=0;
	cin >> cooltime >> delay >> per_damage >> zisok >> summon_delay >> summon_per_damage >> summon_zisok >> direct >> req_gauge >> inc_gauge;;
	//if (id != 5 ) cout << cooltime << delay << per_damage << zisok << summon_delay << summon_per_damage << summon_zisok;
	if (cooltime <= 1)
	{
		if (summon_zisok==1)
		{
			summon_zisok=simulation_time;
			cooltime = simulation_time;
		}
		return;
	}
	if (delay == 0) delay = 1;
	cooltime = cooltime * (100-mer)/100;
	if (cooltime <= 10000)
	{
		cooltime = cooltime * (100-5*coolgam) / 100;
	}
	else if (cooltime - coolgam * 1000 <= 10000)
	{
		cooltime = (100000-5*(1000*coolgam-(cooltime-10000))) / 10;
	}
	else cooltime -= coolgam*1000;
}

class player
{
public:
	player();
	~player();
	vector<pair<int,int>> schedule;
	vector<int> spec;
	double stat;
	double attack;
	double attack_per;
	double damage;
	double final_damage;
	double ignore;
	double cri_damage;
	double weapon;
	double usage;
    double stat_per;
	int fix_stat;
private:

};

player::player()
{
}

player::~player()
{
}

class final_buff
{
public:
	final_buff();
	~final_buff()
	{
	}
	int final_attack;
	int delay;
	int min_delay;
	int dec_delay;
	int last_active;
	int cur_delay;
	int per_damage;
	long long dpm;
	int use;
	int atk_id;
	int buf_id;
	double buf_time;
private:
};

final_buff::final_buff()
{
	use=0;
        last_active=0;
        cur_delay=0;;
        dpm=0;
	cin >> final_attack >> delay >> min_delay >> dec_delay >> per_damage >> atk_id >> buf_id >> buf_time;
		
}
class msdp
{
public:
	msdp()
	{
		id=0;
		buf=0;
		time = 0;
	}
	~msdp()
	{
	}
	int cooltime;
	long long tdpm;
	int id;
	int temp;
	int per_damage;
	int buf;
	int time;
	friend bool operator < (const msdp& msd,const msdp& msd2)
	{
		if (msd.cooltime == msd2.cooltime) return msd.tdpm>msd2.tdpm;
		return msd.cooltime < msd2.cooltime;
	}
private:
};

class gauge
{
public: 
	gauge();
	~gauge()
	{
	}
	int max;
	int damage;
	int final_damage;
	int attack;
	int cur;
private:
};

gauge::gauge()
{
	cur=0;
	cin >> max >> damage >> final_damage >> attack;
}

vector<attack> atk;
buff buf[100];
vector<int> buff_list;
long long dpm_max=0;
long long cur_dpm=0;
int bufm;
player pla;
player max_pla;
vector<attack> max_atk;
buff max_buf[100];
vector <int> redo;
vector <pair<pair<int,int>,int>> rere;
int res_sch=0;
vector<final_buff> fibuf,maxfibuf;
int fibufm;
vector<msdp> msdpm,maxmsdpm;
vector<gauge> gaz;
int gazm;
int attack_length;

long long time_dpm_calc(int cooltime)
{
	double stat=pla.stat;
    long long attack=pla.attack;
    double attack_per=pla.attack_per;
    double damage=pla.damage;
    double final_damage=pla.final_damage;
    double ignore=pla.ignore;
	double cri_damage=pla.cri_damage;
    double weapon=pla.weapon;
	double usage=pla.usage;
	double stat_per=pla.stat_per;
	long long tdpm =stat * attack * attack_per * damage * final_damage * (1-3*(1-ignore)) * cri_damage * weapon * usage;
	for(gauge i : gaz)
	{
		if(i.cur*i.final_damage)final_damage=final_damage*(100+i.final_damage*i.cur)/100.0;
		damage+=i.damage*i.cur/100.0;
		attack+=i.attack*i.cur;
	}
	for(int i=0;i<bufm;i++)
	{
		for (int j : buf[i].schedule)
		{
			if(j<=cooltime&&j+buf[i].zisok>=cooltime)
			{
				if (buf[i].final_damage) final_damage=final_damage*(100+buf[i].final_damage)/100.0;
				damage+=buf[i].damage/100.0;
				stat=(stat-pla.fix_stat)*(buf[i].stat_per/100.0+stat_per)/stat_per+pla.fix_stat;
				stat_per+=buf[i].stat_per/100.0;
				cri_damage += buf[i].cri_damage/100.0;
				stat += buf[i].stat * 4 * stat_per;
				attack += buf[i].attack;
				attack_per += buf[i].attack_per/100.0;
				break;
			}
		}
	}
	//cout <<  stat * attack * attack_per * damage * final_damage * (1-3*(1-ignore)) * cri_damage * weapon * usage << endl;
	return stat * attack * attack_per * damage * final_damage * (1-3*(1-ignore)) * cri_damage * weapon * usage;
}

int able_skill(int cooltime, attack k)
{
	//cout << k.atk_id << " " <<cooltime << endl;
	int res = k.zisok;
	res_sch=0;
	if (cooltime + k.delay > simulation_time) return 0;
	for (int i : k.schedule)
	{
		if ((i<cooltime&&i+k.cooltime>cooltime)||(i<cooltime+k.cooltime&&i>cooltime)) return 0;
	}
	for (pair<int,int> i : pla.schedule)
	{
		if(i.first>cooltime+k.delay) res=min(res,i.first-cooltime-k.delay);
		if (i.first<=cooltime+k.delay && cooltime <= i.second)
		{
			 res_sch=i.second;
			 return 0;
		}
	}
	res = min(res,simulation_time-cooltime-k.delay);
	if (k.zisok == 0) return 1;
	else return res;
}

int retemp=0;

int apply_skill(int cooltime,int k)
{
	long long ap_dpm=0,tdpm;
	msdp *msd;
	int temp = able_skill(cooltime,atk[k]);
	if (temp==0) return 0;
	if (temp==1)
	{
		pla.schedule.push_back(make_pair(cooltime,cooltime+atk[k].delay));
		atk[k].schedule.push_back(cooltime);
		msd = new msdp();
		msd->cooltime = cooltime;
		msd->id = k;
		msd->temp = 1000;
		msd->per_damage=atk[k].per_damage;
		msdpm.push_back(*msd);
		delete msd;
		for (int i=1;i*atk[k].summon_delay<atk[k].summon_zisok;i++)
		{
			int cur_cool = cooltime + i*atk[k].summon_delay;
			if (cur_cool>simulation_time) break;
			msd = new msdp();
			msd->cooltime = cur_cool;
			msd->id = k;
			msd->temp = 1000;
			msd->per_damage=atk[k].summon_per_damage;
			msdpm.push_back(*msd);
			delete msd;
		}
	}
	else if(temp > 1)
	{
		pla.schedule.push_back(make_pair(cooltime,cooltime+atk[k].delay+temp));
		atk[k].schedule.push_back(cooltime);
		int temp2=temp;
		for (;temp2 > 1000;temp2-=1000,cooltime+=1000) 
		{
			msd = new msdp();
			msd->cooltime = cooltime;
			msd->id = k;
			msd->temp = 1000;
			msd->per_damage=atk[k].per_damage;
			msdpm.push_back(*msd);
			delete msd;
		}
		msd = new msdp();
		msd->cooltime = cooltime;
		msd->id = k;
		msd->temp = temp2;
		msd->per_damage=atk[k].per_damage;
		msdpm.push_back(*msd); 
		delete msd;
	}
	return temp;
}

int apply_buff_deal(int cooltime,int m)
{
	msdp msd1;
	msd1.cooltime = msdpm[0].cooltime;
	msd1.tdpm = msdpm[0].tdpm;
	msd1.buf = 1;
	msd1.id	= m;
	msd1.temp=1000;
	msd1.per_damage=buf[m].final_attack;
	msd1.time = buf[m].final_time;
	msdpm.push_back(msd1);
	return 0;
}

int apply_final(int cooltime,int per_damage,int tdpm)
{
	msdp *msd = new msdp();
	msd->cooltime = cooltime;
	msd->tdpm = tdpm;
	msd->id = 0;
	msd->buf = 2;
	msd->temp = 1000;
	msd->per_damage=per_damage/100;
	msdpm.push_back(*msd);
	delete msd;
	return 0;
}

void els_calc()
{
	int temp=0;
	int temp2;//cout << 1;
	sort(pla.schedule.begin(),pla.schedule.end());
	int bak=0,conti=0;
	int cur_cool;
	long long temp_dpm=0;
	for (int i=0;i<atk.size();i++) sort(atk[i].schedule.begin(),atk[i].schedule.end());
	int ss,dz=-1,fin;
	for (int i=0;i<atk.size();i++)
	{
		if(atk[i].cooltime==0) 
		{
			dz=i;
			break;
		}
		atk[i].schedule.push_back(simulation_time);
		ss=atk[i].schedule.size();
		for(int j=0;j<ss;j++)
		{
			cur_cool=atk[i].schedule[j]+atk[i].cooltime;
			for (;cur_cool+atk[i].cooltime<=atk[i].schedule[j+1];cur_cool+=max(atk[i].cooltime,atk[i].summon_zisok))
			{
				temp = apply_skill(cur_cool,i);
				if (temp==0)
				{
					for (pair<int,int> l : pla.schedule)
					{
						if (l.first < cur_cool + atk[i].delay && cur_cool < l.second )
						{
							cur_cool = l.second+1;
							break;
						}
					}
					temp = apply_skill(cur_cool,i);
				}
			}
		}
		sort(atk[i].schedule.begin(),atk[i].schedule.end());
		atk[i].schedule.pop_back();
		sort(pla.schedule.begin(),pla.schedule.end());
	}
	pair<int,int> a;
	msdp *msd;
	pla.schedule.push_back(make_pair(simulation_time,simulation_time+1));
	a = pla.schedule[0];
	if (dz>=0)
	{
		for (pair<int ,int> l : pla.schedule)
		{
			if (l.first<0) continue;
			if(a==l) continue;
			for (cur_cool=a.second+1; cur_cool+atk[dz].delay <= l.first; cur_cool+=atk[dz].delay+1)
			{
				apply_skill(cur_cool,dz);
			}
			a=l;
		}
		sort(pla.schedule.begin(),pla.schedule.end());
		pla.schedule.pop_back();
	}
	sort(msdpm.begin(),msdpm.end());
	vector <int> final;
	long long final_attack_dpm =0;
	for (int l =0;l<bufm;l++) if(buf[l].final_attack>0) final.push_back(l);
	for (int m:final)
	{
		if (buf[m].atk_id && buf[m].atk_id!=msdpm[0].id) continue;
		buf[m].last_attack=msdpm[0].cooltime;
		apply_buff_deal(msdpm[0].cooltime,m);
	}
	sort(msdpm.begin(),msdpm.end());
	int mm=0;
	for (msdp i : msdpm)
	{
		for (int m:final)
		{
			if (buf[m].atk_id && buf[m].atk_id!=atk[i.id].atk_id) continue;
			if (buf[m].last_attack+buf[m].final_cool <= i.cooltime)
			{
				int zl = 0;
				for (int k : buf[m].schedule)
				{
					if (k<=i.cooltime && k+buf[m].zisok >= i.cooltime)
					{
						zl=1;
						break;
					}
				}
				if (zl)
				{
					long long  tdpm;
					apply_buff_deal(i.cooltime,m);
					buf[m].last_attack=i.cooltime;
				}
			}
		}
	}
	sort(msdpm.begin(),msdpm.end());
	int tempc=-1;
	int msdpms = msdpm.size();
	int per_damage;
	for (int i=0;i<msdpms;i++)
	{
		per_damage = msdpm[i].per_damage;
		if (msdpm[i].time) per_damage*=msdpm[i].time;
		long long tdpm = time_dpm_calc(msdpm[i].cooltime);
		msdpm[i].tdpm = tdpm;
		cur_dpm += tdpm*per_damage*msdpm[i].temp/100000;
		if (msdpm[i].buf) 
		{
			for (int j=0;j<gazm;j++)gaz[j].cur = min((double)gaz[j].max,gaz[j].cur+buf[msdpm[i].id].inc_gauge);
			if (msdpm[i].buf==1)
			{
				buf[msdpm[i].id].dpm+=tdpm*per_damage*msdpm[i].temp/100000;
				buf[msdpm[i].id].use+= max(msdpm[i].time,1);
			}
			if (!buf[msdpm[i].id].direct) continue;
		}
		else
		{
			for(gauge j : gaz) j.cur = min((double)j.max,j.cur+atk[msdpm[i].id].inc_gauge);
			atk[msdpm[i].id].dpm+=tdpm*per_damage*msdpm[i].temp/100000;
			atk[msdpm[i].id].use+=max(msdpm[i].time,1);;
			if (atk[msdpm[i].id].direct==0) continue;
		}
		for (int j=0;j<fibufm;j++)
		{	
			int buff_active=0;
			if (!msdpm[i].buf&&atk[msdpm[i].id].direct!=1&&atk[msdpm[i].id].direct!=j) continue;
			if (fibuf[j].per_damage) per_damage = fibuf[j].per_damage;
			if (msdpm[i].time) 
			{
				per_damage*=msdpm[i].time;
				//cout << per_damage << endl;
			}
			if (fibuf[j].buf_id) 
			{
				int temp_id=0;
				for (int k=0;k<bufm;k++)
				{
					if (buf[k].buf_id == fibuf[j].buf_id)
					{
						temp_id=k;
						break;
					}
				}
				for(int k : buf[temp_id].schedule)
				{
					if (k<= msdpm[i].cooltime && msdpm[i].cooltime < k+buf[temp_id].zisok)
					{
						buff_active=1;
						break;
					}
				}
				if (buff_active) 
				{
					per_damage *= fibuf[j].buf_time;
					if (!per_damage) continue;
				}
			}
			if (fibuf[j].atk_id)
			{
				int temp_id=0;
				for (int k=0;k<atk.size();k++) 
				{
					if (atk[k].atk_id == fibuf[j].atk_id) 
					{
						temp_id=k;
						break;
					}
				}
				for (int k : atk[temp_id].schedule)
				{
					if (k <= msdpm[i].cooltime && msdpm[i].cooltime < k+atk[temp_id].summon_zisok) 
					{
						buff_active=1;
						break;
					}
				}
				if (buff_active) continue;
			}
			if(fibuf[j].cur_delay+fibuf[j].last_active <= msdpm[i].cooltime)
			{
				if (per_damage>0)
				{
					fibuf[j].cur_delay = fibuf[j].delay;
					fibuf[j].last_active = msdpm[i].cooltime;
					cur_dpm+=tdpm*per_damage/100;
					fibuf[j].dpm+=tdpm*per_damage/100;
					fibuf[j].use+=max(msdpm[i].time,1);
					apply_final(msdpm[i].cooltime,tdpm,per_damage);
				}
				else
				{
					fibuf[j].cur_delay = fibuf[j].delay;
					fibuf[j].last_active = msdpm[i].cooltime;
					cur_dpm+=tdpm*per_damage*msdpm[i].temp*fibuf[j].final_attack/10000000;
					fibuf[j].dpm+=tdpm*per_damage*msdpm[i].temp*fibuf[j].final_attack/10000000;
					fibuf[j].use+=max(msdpm[i].time,1);
					apply_final(msdpm[i].cooltime,per_damage*fibuf[j].final_attack/100,tdpm);
					atk[msdpm[i].id].dpm+=tdpm*per_damage*msdpm[i].temp*fibuf[j].final_attack/10000000;
				}
			}
			else
			{
				fibuf[j].cur_delay = max(fibuf[j].min_delay,fibuf[j].cur_delay-fibuf[j].dec_delay);
			}
		}
	}
	if (dpm_max<cur_dpm) 
	{
		for (int i=0;i<bufm;i++) max_buf[i]=buf[i];
		max_atk.clear();
		for (attack i : atk) max_atk.push_back(i);
		max_pla=pla;
		dpm_max=cur_dpm;
		maxmsdpm=msdpm;
		maxfibuf = fibuf;
	}
        //cout << buff_list[0] << " " << buff_list[1] << " " << cur_dpm << endl;
	
	/*if(buff_list[0]==190000&&buff_list[1]==90000&&buf[1].schedule[1]==190000&&buf[4].schedule[1]==90000)
	{
		for (int i=0;i<bufm;i++)
		{
			cout << buf[i].buf_id << endl;
			for (int j:buf[i].schedule) cout << j << " ";
			cout << endl << endl;
		}
	}
	} 
		
		if (atk[3].atk_id==1&&atk[3].schedule[0] == 1833 && atk[0].schedule.size()==5 && atk[2].schedule.size()>=4 &&atk[1].schedule.size()>=4)
		{
		for (attack i : atk)
		{
			 cout << i.atk_id << endl;
			 sort(i.schedule.begin(),i.schedule.end());
			 for (int j : i.schedule) cout << j << " ";
			 cout << endl << endl;
		}
		for (pair <int,int> i : pla.schedule) cout << i.first << " " << i.second << "  ";
		cout << endl << cur_dpm +temp << endl << endl;
		}
	for(int i=0;i<atk.size();i++)
	{
		for (int j=0;j<atk_push[atk[i].atk_id-1];j++) atk[i].schedule.pop_back();
	}
	for (int j=0;j<pla_push;j++) pla.schedule.pop_back();
	for(int j=0;j<redo1;j++) redo.pop_back();*/
	//for (attack i : atk) cout << i.schedule.size() << " ";
	//cout << pla.schedule.size() << endl;
}

vector<int> deal;

void follow_buff(int i,int cur_cool,int next_cool)
{
	if (i>=buff_list.size()) return;
	int temp_cool = cur_cool+buff_list[i];
	for (;temp_cool<next_cool;temp_cool+=buff_list[i])
	{
		deal.push_back(temp_cool);
	}
	temp_cool = cur_cool;
	for(;temp_cool+buff_list[i]<next_cool;temp_cool+=buff_list[i])
	{
		follow_buff(i+1,temp_cool,temp_cool+buff_list[i]);
	}
	follow_buff(i+1,temp_cool,next_cool);
}

void buff_sup(int i,int j,int k,int cur_cool,int next_cool)
{
	if (k>=buff_list.size()) return;
	int cnt = (buf[i].cooltime - 1)/buff_list[k] +1;
	cnt*=buff_list[k];
	buff_sup(i,j,k+1,cur_cool,cur_cool+cnt);
	for(int l=0;;l++)
	{
		cur_cool+= cnt;
		if (cur_cool+buf[i].cooltime>=next_cool || cur_cool>simulation_time) return;
		buf[i].schedule.push_back(cur_cool);
		buff_sup(i,j,k+1,cur_cool,cur_cool+cnt);
	}
}

void apply_buff()
{
	int cur_cool;
	int key = 0;
	if (buff_list.size()==0) return;
	for (int l=0;l<pow(3,bufm);l++)
	{
		int divd=l;
		key = 0;
		int s_delay=0,f_delay=0,z_delay=0;
		for (int i=bufm-1;i>=0;i--)
		{
			buf[i].schedule.clear();
			if (divd % 3 == 2)
			{
				for (int j = 0;; j++)
				{
					cur_cool = j * buff_list[0] + attack_length - buf[i].cooltime;
					cur_cool -= s_delay + buf[i].delay;
					s_delay+=buf[i].delay + 1;
					if (cur_cool > simulation_time) break;
					buf[i].schedule.push_back(cur_cool);
					if(cur_cool>=0) pla.schedule.push_back(make_pair(cur_cool,cur_cool+buf[i].delay));
					int cnt = (buf[i].cooltime - 1) / buff_list[0];
					buff_sup(i, j, 1, cur_cool, cur_cool + (cnt + 1) * buff_list[0]);
					j += cnt;
				}
			}
			else if (divd % 3 == 1)
			{
				for(int j=0;;j++)
				{
					cur_cool=j*buf[i].cooltime - buf[i].delay - f_delay;
					f_delay += buf[i].delay + 1;
					if (cur_cool>simulation_time) break;
					buf[i].schedule.push_back(cur_cool);
					if(cur_cool>=0) pla.schedule.push_back(make_pair(cur_cool,cur_cool+buf[i].delay));
				}
			}
			else
			{
				if (buff_list[0]==buf[i].cooltime)
				{
					key=1;
					break;
				}
				for(int j=0;;j++)
				{
					cur_cool=j*buff_list[0] - buf[i].delay - z_delay;
					z_delay += buf[i].delay + 1;
					if (cur_cool>simulation_time) break;
					buf[i].schedule.push_back(cur_cool);
					if(cur_cool>=0) pla.schedule.push_back(make_pair(cur_cool,cur_cool+buf[i].delay));
					int cnt = (buf[i].cooltime-1) / buff_list[0];
					buff_sup(i,j,1,cur_cool,cur_cool+(cnt+1)*buff_list[0]);
					j+=cnt;
				}
			}
			sort(buf[i].schedule.begin(),buf[i].schedule.end());
			divd/=3;
		}
			//int key2=1;
			//for (int z=0;z<bufm;z++) if (buf[z].schedule.size()<1) key2=0;
		       	//if (key2) for(int z=0;z<=simulation_time;z+=1000) cout << z << " "<< time_dpm_calc(z) << endl;
		if(key==0) 
		{
			els_calc();
			pla.schedule.clear();
			for (int k=0;k<bufm;k++)
			{
				buf[k].dpm=0;
				buf[k].use=0;
			}
			for (int k=0;k<atk.size();k++)	
			{
				atk[k].schedule.clear();
				atk[k].dpm=0;
				atk[k].use=0;
			}
			for (int k=0;k<fibufm;k++)
			{
				fibuf[k].last_active=0;
				fibuf[k].cur_delay=0;
				fibuf[k].dpm=0;
				fibuf[k].use=0;
			}
			cur_dpm=0;
			msdpm.clear();
		}
	}
}

void deal_calc()
{
	//int min_cool;
	cur_dpm=0;
	int cur_cool=0;
	//sup_deal(0,0,0,0,0);
	int max_cool=0;	
	for (int l=0;l<(1<<atk.size());l++)
	{
		for (int i:deal)
		{
			max_cool=0;
			cur_cool=i;
			int pow=1;
			int plde;
			if (cur_cool>simulation_time) break;
			for(int k=0;k<atk.size();k++)
			{
				if (max_cool > 0 && max_cool - cur_cool < atk[k].cooltime)
				{
					if (l&pow)
					{
						if (max_cool<simulation_time)
						{
							plde = apply_skill(max_cool,k);
							if (plde) max_cool+=atk[k].delay+(plde>1?plde:0)+1;
						}
					}
					else 
					{
						plde = apply_skill(cur_cool,k);
						//if(atk[k].atk_id==1) cout << cur_cool << " " << plde << endl;
						if (plde) cur_cool+=atk[k].delay+(plde>1?plde:0)+1;
						if (cur_cool>simulation_time) break;
					}
					pow*=2;
					continue;
				}
				plde = apply_skill(cur_cool,k);
				if (l&pow)
				{
					if (cur_cool+atk[k].cooltime <simulation_time)
					{
						//if (k==0)cout << cur_cool + atk[k].cooltime << endl;
						int plde2 = apply_skill(cur_cool+atk[k].cooltime,k);
						if (max_cool==0) 
						{
							if (plde2)max_cool = cur_cool+atk[k].cooltime+atk[k].delay + (plde2>1 ? plde2:0) +1;
							else max_cool = cur_cool+atk[k].cooltime;
						}
					}
				}
				else
				{
					if (max_cool)
					{
						int plde3 = apply_skill(max_cool,k);
						if (plde3) max_cool += atk[k].delay + (plde3>1?plde3:0) +1;
					}
				}
				pow*=2;
				if (plde) cur_cool+=atk[k].delay+(plde>1?plde:0)+1;
				if (cur_cool>simulation_time) break;
			}
		}
		pair<int,int> a=pla.schedule[0];
		for (pair<int,int> i : pla.schedule)
		{
			if (i.first-a.second > 1)
			{
				break;
			}
			attack_length = i.second;
			a=i;
		}
		cout << attack_length << endl;
		apply_buff();
	}
}



void buffclear()
{
	for (int i = 0; i < bufm; i++)
	{
		buf[i].schedule.clear();
	}
	cur_dpm=0;
}

void buff_calc(int start)
{
	buff_list.push_back(buf[start].cooltime);
	int i, key = 0;
	for (i = start + 1; i < bufm; i++)
	{
		if (buf[i].cooltime * 2 <= buf[start].cooltime)
		{
			buff_calc(i);
			key = 1;
			break;
		}
	}
	if (key == 0)
	{
		deal.push_back(0);
		follow_buff(0,0,simulation_time);
		deal_calc();
		deal.clear();
		buffclear();
	}
	buff_list.pop_back();
	for (i = start + 1; i < bufm; i++)
	{
		if (buf[i].cooltime >= 60000 && buf[i].cooltime != buf[start].cooltime)
		{
			buff_calc(i);
			break;
		}
	}
}


int main(void)
{
	int i = 0, temp;
	cin >> simulation_time >> coolgam;
	cin >> pla.stat >> pla.attack >> pla.attack_per >> pla.damage >> pla.final_damage >> pla.ignore >> pla.cri_damage >> pla.weapon >> pla.usage>> pla.stat_per >> pla.fix_stat;
	
	//cout << pla.stat << endl <<  pla.attack << endl <<  pla.attack_per << endl << pla.damage << endl << pla.final_damage << endl << pla.ignore << endl << pla.cri_damage << endl << pla.weapon << endl << pla.usage << endl << pla.stat_per << endl << pla.fix_stat << endl;
	while (1)
	{
		cin >> temp;
		cout << temp;
		if (temp)
		{
			buf[i].input(temp);
			i++;
		}
		else
		{
			bufm = i; //buf[0]~buf[bufm-1]
			break;
		}
	}
	attack* atk_temp;
	while (1)
	{
		cin >> temp;
		if (temp)
		{
			atk_temp = new attack();
			atk_temp->input(temp);
			atk.push_back(*atk_temp);
		}
		else
		{
			break;
		}
	}
	cin >> fibufm;
	for (int j=0;j<fibufm;j++)
	{
		fibuf.push_back(*(new final_buff()));
	}
	cin >> gazm;
	for (int j=0;j<gazm;j++) gaz.push_back(*(new gauge()));
	cout << 382491 << endl;
	sort(&buf[0], &buf[bufm]);
	sort(atk.begin(),atk.end());
	buff_calc(0);
	for (int j=0;j<atk.size();j++) 
	{
		if (atk[j].cooltime >0 && atk[j].cooltime < 15000) atk[j].per_damage *= 4;
	}
	sort(atk.begin(),atk.end());
	for (int j=0;j<atk.size();j++)
	{
		if (atk[j].cooltime>0 && atk[j].cooltime < 15000) atk[j].per_damage /= 4;
	}
	//for (attack z : atk) cout << z.atk_id << " " << z.per_damage << " ";
	cout << endl;
	buff_calc(0);
	cout <<dpm_max << endl;
	cout << "| BUFF |" << endl;

	for (i=0;i<bufm;i++)
	{
		cout << max_buf[i].buf_id << endl;
		for (int j : max_buf[i].schedule) cout << j << "\t";
		cout << endl;
	}
	cout << endl;
	cout << "| SKILL |" << endl;
	for (attack j : max_atk)
	{
		cout << j.atk_id << endl;
		sort(j.schedule.begin(),j.schedule.end());
		for (int i : j.schedule) cout << i << "\t";
		cout << endl;
	}
	cout << endl;
	cout << "| PLAYER |" << endl;
	sort(max_pla.schedule.begin(),max_pla.schedule.end());
	for (pair<int,int> j : max_pla.schedule) cout << j.first << "\t" << j.second << " \t";
	cout << endl;
	i=1;
	long long msd = 0;
	int divd = 1000;
	sort(maxmsdpm.begin(),maxmsdpm.end());
	for (msdp j : maxmsdpm)
	{
		if(j.cooltime >= i*divd)
		{
			cout << msd << endl;
			msd = 0;
			i++;
		}
		msd+=j.tdpm*j.per_damage*j.temp/100000;
		//if (i==8000) cout << j.first << " " << j.second << endl; 
	}
	cout << msd << endl;
       cout<< dpm_max << endl;
       for (int j=0;j<bufm;j++)
       {
	       cout <<fixed;
	       cout.precision(2);
	       cout <<max_buf[j].buf_id<<" : " << (double)max_buf[j].dpm*100/dpm_max<<"% " << max_buf[j].dpm << " " << max_buf[j].use << endl;
       }
       for(attack j : max_atk)
       {
	       cout << fixed;
	       cout.precision(2);
		cout << j.atk_id << " : " << (double)j.dpm*100/dpm_max << "% " << j.dpm<< " " << j.use << endl;
       }
       for (final_buff j :maxfibuf)
       {
	       cout << fixed;
               cout.precision(2);
               cout << (double)j.dpm*100/dpm_max << "% " << j.dpm << " " << j.use << endl;
       }

	//for (int i=0;i<bufm;i++) buf[i].schedule.push_back(0);
	//for (int i=0;i<40000;i+=100)cout << i << " " <<  time_dpm_calc(i) << endl;
}
