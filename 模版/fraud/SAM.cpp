#define MAXN 100010

//#define SUFFIX_TREE

struct SAM{
	SAM* go[26];
	SAM* par;
	int maxl;
#ifdef SUFFIX_TREE
	int st_head;
#endif
	SAM(int l=0):maxl(l) {
#ifdef SUFFIX_TREE
		st_head = 0;
#endif
	}
	SAM& operator=(const SAM& s){
		maxl = s.maxl;
		par = s.par;
		memcpy(go, s.go, sizeof(go));
		return *this;
#ifdef SUFFIX_TREE
		st_head = s.st_head;
#endif
	}
	int minl() {
		return par?par->maxl+1:maxl;
	}
} node[MAXN<<1], *last, *root;
int n_node;

SAM* newnode() {
	return &node[n_node++];
}

void init_sam() {
	n_node = 0;
	last = root = newnode();
}

void extend(int c) {
	SAM* p = last, *np = newnode();
	np->maxl = p->maxl + 1;
	for(; p && !p->go[c]; p = p->par) p->go[c] = np;
	if(!p) np->par = root;
	else {
		SAM* q = p->go[c];
		if(q->maxl == p->maxl + 1) np->par = q;
		else {
			SAM* nq = newnode();
			*nq = *q;
			nq->maxl = p->maxl + 1;
			np->par = q->par = nq;
			for(;p && p->go[c] == q ;p = p->par) p->go[c] = nq;
		}
	}
	last = np;
#ifdef SUFFIX_TREE
	last->st_head = 1;
#endif
}

string str;

#ifdef SUFFIX_TREE

VI Map[MAXN<<1];

void init_suffixtree(char* s) {
	init_sam();
	int l = strlen(s);
	REP(i,l) extend(s[l-i-1]);
	REP(i,n_node) Map[i].clear();
	REP(i,n_node) if(node[i].st_head) {
		SAM* p = &node[i];
		while(p!=root) {
			string ss = str.substr(p->minl()-1,p->maxl-p->minl()+1);
			reverse(ss.begin(),ss.end());
			cout<<ss<<" -> ";
			p=p->par;
		}
		cout<<"|"<<endl;
	}
}

#endif

