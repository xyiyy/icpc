template <typename T>
class Matrix {
	public:
		T *m;
		int r,c;
		Matrix(int _r,int _c)
		{
			r=max(_r,1);
			c=max(_c,1);
			m=new T[r*c];
			CLR(m,0);
		}
		Matrix(const Matrix& mat)
		{
			r = mat.r;
			c = mat.c;
			m = new T[r*c];
			for(int i = 0; i < r*c; i++)
				m[i] = mat.m[i];
		}
		~Matrix()
		{
			delete[] m;
		}
		T* operator[](int n)
		{
			return m+c*n;
		}
		Matrix &operator*=(const Matrix &mat)
		{
			if(c==mat.r)
			{
				T* tmp=new T[r*mat.c];
				for(int i=0;i<r;i++)
				for(int j=0;j<mat.c;j++)
				{
					tmp[i*mat.c+j]=0;
					for(int k=0;k<c;k++)
					{
						tmp[i*mat.c+j] += m[i*c+k] * mat.m[k*mat.c+j];
						//tmp[i*mat.c+j]%=MOD;
					}
				}
				delete[] m;
				m=tmp;
				c=mat.c;	
				return *this;
			}
			else 
			{
				printf("WA\n");
				return *this;
			}
		}
		Matrix& operator=(const Matrix& mat)
		{
			delete[] m;
			r = mat.r;
			c = mat.c;
			m = new T[r*c];
			for(int i = 0; i < r*c; i++)
				m[i] = mat.m[i];
			return *this;
		}
		Matrix operator*(const Matrix& mat)
		{
			Matrix t(*this);
			t*=mat;
			return t;
		}
		void Init()
		{
			CLR(m,0);
			for(int i = 0; i < r*c; i++)
				m[i] = i%c==i/c ? 1:0;
		}
		void display()
		{
			for(int i = 0; i < r; i++)
			{
				for(int j = 0; j < c; j++)
				{
					if(j) cout<<' ';
					cout<<(*this)[i][j];
				}
				cout<<endl;
			}
		}
		Matrix operator^(int n)
		{
			if(r == c && n > 0)
			{
				//int m=r;
				Matrix ans(r,r), tmp(*this);
				ans.Init();
				while(n)
				{
					if(n&1) ans*=tmp;
					n>>=1;
					//cout<<n<<endl;
					tmp*=tmp;
					//cout<<"ok"<<endl;
				}
				return ans;
			}
			return *this;
		}
		void Unit()
		{
		}
};
typedef Matrix<int> Matint;
typedef Matrix<ll> Matll;
///////**********************//////
//main函数里的快速幂
int n;
while(n)
{
	if(n&1) ans=temp*ans;
	temp*=temp;
	n>>=1;
}

		
		
		
		
