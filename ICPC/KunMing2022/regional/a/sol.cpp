#include<bits/stdc++.h>
using namespace std;
typedef long long ll;







struct Aa{
	ll mass;
	ll NH2;
	ll COOH;
	int id;
	vector<vector<string>>gnh2;
	vector<int>nh2noline;
	vector<vector<string>>gcooh;
	vector<int>coohnoline;
	inline void out(int type,int num,int j) {
	    if(type==1)cout << gnh2[num][j];
	    else{
	        cout << gcooh[num][j];
		}
    }
};
	map<string,Aa>mp;
	vector<string>an(10);

void f(int ii,int iii,int jj,int jjj){
    	if(mp[an[ii]].coohnoline[iii]<mp[an[jj]].nh2noline[jjj]){
    		for(int i=0;i<mp[an[jj]].nh2noline[jjj]-mp[an[ii]].coohnoline[iii];++i){
    		    mp[an[ii]].out(0,iii,mp[an[ii]].id);
				cout<<endl;
			}
		}
		else{
			for(int i=0;i<mp[an[ii]].coohnoline[iii]-mp[an[jj]].nh2noline[jjj];++i){
			mp[an[jj]].out(1,jjj,mp[an[jj]].id);
			cout<<endl;
			}
		}
		///////////////////////////////////////////////////////////////////////////////////////////
		
	//	int d=min(mp[an[0]].id-mp[an[0]].coohnoline[0],mp[an[0]].id-mp[an[0]].nh2noline[0]);
		if(mp[an[ii]].id-mp[an[ii]].coohnoline[iii]<mp[an[jj]].id-mp[an[jj]].nh2noline[jjj]){
			for(int i=0;i<mp[an[ii]].coohnoline[iii];++i){
				mp[an[ii]].out(0,iii,i);
				if(i==mp[an[ii]].coohnoline[iii]-1)cout<<'-';
				else cout<<' ';
				mp[an[jj]].out(1,jjj,i);
				cout<<endl;
			}
			for(int i=mp[an[jj]].nh2noline[jjj];i<mp[an[jj]].id;++i){
				if(i>mp[an[ii]].id)mp[an[ii]].out(0,iii,mp[an[ii]].id);
				else mp[an[ii]].out(0,iii,i);
			    mp[an[jj]].out(1,jjj,i);
			    cout<<endl;
			}
		}
		else{
			for(int i=0;i<mp[an[ii]].coohnoline[iii];++i){
				mp[an[ii]].out(0,iii,i);
				if(i==mp[an[ii]].coohnoline[iii]-1)cout<<'-';
				else cout<<' ';
				mp[an[jj]].out(1,jjj,i);
				cout<<endl;
			}
			for(int i=mp[an[ii]].coohnoline[iii];i<mp[an[ii]].id;++i){
			    mp[an[ii]].out(0,iii,i);
			    if(i>mp[an[jj]].id)mp[an[jj]].out(1,jjj,mp[an[jj]].id);
			    else mp[an[jj]].out(1,jjj,i);
			    cout<<endl;
			}
		}
	}


int main(){
	map<string,int> mmp;
	an[0]="Ala";mmp["Ala"]=0;
	an[1]="Asn";mmp["Asn"]=1;
	an[2]="Asp";mmp["Asp"]=2;
	an[3]="Cys";mmp["Cys"]=3;
	an[4]="Gln";mmp["Glb"]=4;
	an[5]="Glu";mmp["Glu"]=5;
	an[6]="Gly";mmp["Gly"]=6;
	an[7]="Met";mmp["Met"]=7;
	an[8]="Ser";mmp["Ser"]=8;
	an[9]="Thr";mmp["Thr"]=9;
	mp[an[0]].mass=89 ;mp[an[0]].NH2=1;mp[an[0]].COOH=1;mp[an[0]].id=7;
	mp[an[0]].gnh2={ 
					   { " H H O    ",
	                     " | | ||   ",
	                     "-N-C-C-O-H",
	                     "  |       ",
	                     "H-C-H     ",
	                     "  |       ",
	                     "  H       ",
	                     "          ",
	                   },
                   };
    mp[an[0]].nh2noline={3};
    mp[an[0]].gcooh={ 
	                    { "  H H O ",
	                      "  | | ||",
	                      "H-N-C-C-",
	                      "    |   ",
	                      "  H-C-H ",
	                      "    |   ",
	                      "    H   ",
	                      "        ",
	                   },
                    };
    mp[an[0]].coohnoline={3};
    
   // f(0,0,0,0);
	mp[an[1]].mass=132;mp[an[1]].NH2=2;mp[an[1]].COOH=1,mp[an[1]].id=9;
	mp[an[1]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " O=C-N-H ",
                         "     |   ",
                         "     H   ",
                         "         "
	                   },
	                   { "  H H O    ",
                         "  | | ||   ",
                         "H-N-C-C-O-H",
                         "    |      ",
                         "  H-C-H    ",
                         "    |      ",
                         " -N-C=O    ",
                         "  |        ",
                         "  H        ",
                         "           "
	                   },
                   };
    mp[an[1]].nh2noline={3,7};
	mp[an[1]].gcooh={ 
	                    {"  H H O  ",
                         "  | | || ",
                         "H-N-C-C- ",
                         "    |    ",
                         "  H-C-H  ",
                         "    |    ",
                         "  O=C-N-H",
                         "      |  ",
                         "      H  ",
                         "         "
	                   },
                    };
	mp[an[1]].nh2noline={3};
	
	
	mp[an[2]].mass=133;mp[an[2]].NH2=1;mp[an[2]].COOH=2,mp[an[2]].id=7;
	mp[an[2]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " O=C-O-H ",
                         "         "
	                   },
                   };
    mp[an[2]].nh2noline={3};
    mp[an[2]].gcooh={ 
	                     { "  H H O  ",
                           "  | | || ",
                           "H-N-C-C- ",
                           "    |    ",
                           "  H-C-H  ",
                           "    |    ",
                           "  O=C-O-H",
                           "         "
	                   },
	                    { "  H H O    ",
                          "  | | ||   ",
                          "H-N-C-C-O-H",
                          "    |      ",
                          "  H-C-H    ",
                          "    |      ",
                          "  O=C      ",
                          "           "
	                   },
                    };
    mp[an[2]].coohnoline={3,7};
    
	mp[an[3]].mass=121;mp[an[3]].NH2=1;mp[an[3]].COOH=1;mp[an[3]].id=7;
	mp[an[3]].gnh2={ 
					   { " H H O    ",
                         " | | ||   ",
                         "-N-C-C-O-H ",
                         "   |      ",
                         " H-C-S-H  ",
                         "   |      ",
                         "   H      ",
                         "          "
                               },
                   };
    mp[an[3]].nh2noline={3};
    mp[an[3]].gcooh={ 
	                    { "  H H O  ",
                          "  | | || ",
                          "H-N-C-C- ",
                          "    |    ",
                          "  H-C-S-H",
                          "    |    ",
                          "    H    ",
                          "         "
                               },
                    };
    mp[an[3]].coohnoline={3};
	
    mp[an[4]].mass=146;mp[an[4]].NH2=2;mp[an[4]].COOH=1;mp[an[4]].id=11;
	mp[an[4]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " O=C-N-H ",
                         "     |   ",
                         "     H   ",
                         "         "
                        },
                       { "  H H O    ",
                         "  | | ||   ",
                         "H-N-C-C-O-H",
                         "    |      ",
                         "  H-C-H    ",
                         "    |      ",
                         "  H-C-H    ",
                         "    |      ",
                         "  O=C-N-   ",
                         "      |    ",
                         "      H    ",
                         "           "
                        },
                   };
    mp[an[4]].nh2noline={3,9};
    mp[an[4]].gcooh={ 
	                   { "  H H O  ",
                         "  | | || ",
                         "H-N-C-C- ",
                         "    |    ",
                         "  H-C-H  ",
                         "    |    ",
                         "  H-C-H  ",
                         "    |    ",
                         "  O=C-N-H",
                         "      |  ",
                         "      H  ",
                         "         "
                        },
                    };
    mp[an[4]].coohnoline={3};
    
    
	mp[an[5]].mass=147;mp[an[5]].NH2=1;mp[an[5]].COOH=2;mp[an[5]].id=9;
	mp[an[5]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " O=C-O-H ",
                         "         "
                        },
                   };
    mp[an[5]].nh2noline={3};
    mp[an[5]].gcooh={ 
	                    {"  H H O  ",
                         "  | | || ",
                         "H-N-C-C- ",
                         "    |    ",
                         "  H-C-H  ",
                         "    |    ",
                         "  H-C-H  ",
                         "    |    ",
                         "  O=C-O-H",
                         "         "
                        },
                        {"  H H O    ",
                         "  | | ||   ",
                         "H-N-C-C-O-H",
                         "    |      ",
                         "  H-C-H    ",
                         "    |      ",
                         "  H-C-H    ",
                         "    |      ",
                         "  O=C-     ",
                         "           "
                        },
                    };
    mp[an[5]].coohnoline={3,9};
	
	mp[an[6]].mass=75 ;mp[an[6]].NH2=1;mp[an[6]].COOH=1;mp[an[6]].id=5;
	mp[an[6]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         "   H     ",
                         "         ",
                               },
                   };
    mp[an[6]].nh2noline={3};
    mp[an[6]].gcooh={ 
	                    { "  H H O ",
                          "  | | ||",
                          "H-N-C-C-",
                          "    |   ",
                          "    H   ",
                          "        "
                               },
                    };
    mp[an[6]].coohnoline={3};
    
	mp[an[7]].mass=149;mp[an[7]].NH2=1;mp[an[7]].COOH=1;mp[an[7]].id=13;
	mp[an[7]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         "   S     ",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         "   H     ",
                         "         "
                        },
                   };
    mp[an[7]].nh2noline={3};
    mp[an[7]].gcooh={ 
	                    {"  H H O ",
                         "  | | ||",
                         "H-N-C-C-",
                         "    |   ",
                         "  H-C-H ",
                         "    |   ",
                         "  H-C-H ",
                         "    |   ",
                         "    S   ",
                         "    |   ",
                         "  H-C-H ",
                         "    |   ",
                         "    H   ",
                         "        "
                        },
                    };
    mp[an[7]].coohnoline={3};
	
	mp[an[8]].mass=105;mp[an[8]].NH2=1;mp[an[8]].COOH=1;mp[an[8]].id=7;
	mp[an[8]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-O-H ",
                         "   |     ",
                         "   H     ",
                         "          "
                        },
                   };
    mp[an[8]].nh2noline={3};
    mp[an[8]].gcooh={ 
	                    {"  H H O  ",
                         "  | | || ",
                         "H-N-C-C- ",
                         "    |    ",
                         "  H-C-O-H",
                         "    |    ",
                         "    H    ",
                         "         "
                        },
                    };
    mp[an[8]].coohnoline={3};
    
    
	mp[an[9]].mass=119;mp[an[9]].NH2=1;mp[an[9]].COOH=1;mp[an[9]].id=9;
	mp[an[9]].gnh2={ 
					   { " H H O   ",
                         " | | ||  ",
                         "-N-C-C-O-H",
                         "   |     ",
                         " H-C-O-H ",
                         "   |     ",
                         " H-C-H   ",
                         "   |     ",
                         "   H     ",
                         "         ",
                       },
                   };
    mp[an[9]].nh2noline={3};
    mp[an[9]].gcooh={ 
	                   { "  H H O  ",
                         "  | | || ",
                         "H-N-C-C- ",
                         "    |    ",
                         "  H-C-O-H",
                         "    |    ",
                         "  H-C-H  ",
                         "    |    ",
                         "    H    ",
                         "         "
                       },
                    };
    mp[an[9]].coohnoline={3};
    
	ll n,m;
	cin>>n>>m;
	vector<string>pro;
	string s;
	for(int i=0;i<n;++i){
		cin>>s;
		pro.push_back(s);
	}
	sort(pro.begin(),pro.end());
	for(int i=0;i<n;++i){
		for(int j=i;j<n;++j)if(mp[pro[j]].mass+mp[pro[i]].mass-18 <=m){
			for(int cooh=0;cooh<mp[pro[i]].COOH;++cooh){
				for(int nh2=0;nh2<mp[pro[j]].NH2;++nh2){
					f(mmp[pro[i]],cooh,mmp[pro[j]],nh2);
					cout<<endl;
				}
			}
		}
		for(int j=i+1;j<n;++j)if(mp[pro[j]].mass+mp[pro[i]].mass-18 <=m){
			for(int nh2=0;nh2<mp[pro[i]].NH2;++nh2){
				for(int cooh=0;cooh<mp[pro[j]].COOH;++cooh){
					f(mmp[pro[j]],cooh,mmp[pro[i]],nh2);
					cout<<endl;
				}
			}
		}
	}
	return 0;
}

