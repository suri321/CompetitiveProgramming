struct cmp {
	bool operator()(const pair<int,int> &a,const pair<int,int> &b) const{
		int len1 = a.S-a.F;
		int len2 = b.S-b.F;
		if(len1==len2){
			return a.F<b.F;
		}else
			return len1>len2;
	}
};

set<pair<int,int>, cmp > st;
