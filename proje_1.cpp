#include <iostream>
#include<stdlib.h>
#include <stdio.h>
#include <string.h>
#include<math.h>
#include<conio.h>
char yaz[]={'Y','A','Z'};
char git[]={'G','Ý','T'};
struct eger{
	char komut[40];
	int numarasi;
	int    indis;
    char data[40];
    int adim;
};
struct bul {
	char   degisken[100];
	int    degeri;
	int    indis;
};
struct nosu{
    int numarasi;
    int komut;
    int indis;
    char data[40];
};
int hangisi(char dizi[],int uzunluk) {
	if(uzunluk==5) {
	char basla[]={'B','A','S','L','A'};
	for(int i=0;i<5;i++) {
		 if(dizi[i]==basla[i]) {
			    if(i==4) return 6;
		    }
		    else break;
	}
    }
	if(uzunluk==3) {
	
		for(int i=0;i<3;i++) {
		    if(dizi[i]==yaz[i]) {
			    if(i==2) return 1;
		    }
		    else break;
	    }
	char git[]={'G','Ý','T'};
	    for(int i=0;i<3;i++) {
		    if(dizi[i]==git[i]) {
			    if(i==2) return 2;
		    }
		    else break;
	    }
	char gir[]={'G','Ý','R'};
	    for(int i=0;i<3;i++) {
		    if(dizi[i]==gir[i]) {
		        if(i==2) return 3;
		    }
		    else break;
        }
    }
    if(uzunluk==5) {
	char bitir[]={'B','Ý','T','Ý','R'};
	    for(int i=0;i<5;i++) {
		    if(dizi[i]==bitir[i]) {
			    if(i==4) return 5;
		    }
		    else break;
	    }
    }
    if(uzunluk==4) {
	char eger[]={'E','G','E','R'};
	    for(int i=0;i<4;i++) {
		    if(dizi[i]==eger[i]) {
			    if(i==3) return 4;
		    }
		    else break;
        }
    }
    if(uzunluk==7) {
	char degilse[]={'D','E','G','Ý','L','S','E'};
	    for(int i=0;i<7;i++) {
		    if(dizi[i]==degilse[i]) {
			    if(i==6) return 9;
		    }
		    else break;
        }
    }
    if(uzunluk==4) {
	char yeni[]={'y','e','n','i'};
	    for(int i=0;i<4;i++) {
		    if(dizi[i]==yeni[i]) {
			    if(i==3) return 8;
		    }
		    else break;
        }
    }
    return 0;
}
int sayimi(char dizi[],int basamak) {
	int toplam=0,a=basamak,j=0,s=0;
	char sayilar[]={'0','1','2','3','4','5','6','7','8','9'};
	for(int j=0;j<basamak;j++){
		a--;	
     	for(int i=0;i<10;i++) { 
		    if(dizi[j]==sayilar[i]) {
			    toplam+=pow(10,a)*i;
			    s++;
		    } 
     	}
    }
   if(s==basamak) return toplam;
   else return -1;
}
int sonucagit(int sayi1,int sayi2,int secenek) {
	switch(secenek) {
		case 1: 
		return sayi1*sayi2;
		break;
		case 2: return sayi1/sayi2;
		break;
		case 3: return sayi1=sayi2;
		break;
		case 4:  return sayi1-sayi2;
		break;
		case 5: return sayi1+sayi2;
		break;
		default: return 0;
	}
}
int islemyap(char dizi[],int uzunluk ) {
	for(int i=uzunluk;i>0;i--) {
		if(dizi[i]=='*') return 1;
		else if(dizi[i]=='/') return 2;
		else if(dizi[i]=='=') return 3;
		else if(dizi[i]=='-') return 4;
		else if(dizi[i]=='+') return 5;
	}
    return -1;
}
int islemyap2(char dizi[],int uzunluk ) {
	for(int i=uzunluk;i>0;i--) {
		if(dizi[i]=='*') return i;
	    else if(dizi[i]=='/') return i;
	    else if(dizi[i]=='=') return i;
		else if(dizi[i]=='-') return i;
		else if(dizi[i]=='+') return i;
	}
    return -1;
}
int arama (struct bul* deg_,char aranan[],int i){
    while(i >=0)  {
        int a = strcmp( aranan,deg_[i].degisken);
        if(a==0) return i;
        else i--;
    }
    return -1;
} 
int egerde(struct bul deg_[],char dizi[],int degisken_sayisi){
	char aranacak1[40],aranacak2[40];
	int i,j=0,sy1,sy2,k=0,isaret,isaret2=0;
	for(i=0;i<strlen(dizi);i++) {
		if((dizi[i] != '<') && (dizi[i] != '=') &&(dizi[i] != '>')&& k==0 ) 	aranacak1[i]=dizi[i];
		else{
			if(k==0) isaret=i;
			if(k==0 && (dizi[i+1])=='=')   isaret2=i+1;
			if(k==0 && (dizi[i+1])=='>')    isaret2=i+1;
			if(k==0 && (dizi[i+1])=='<')    isaret2=i+1;
			if(k==0 && isaret2 != 0)  i++;
			k=1;
			aranacak2[j]=dizi[i+1];
			j++;
		}
	}
	if(arama (deg_,aranacak1,degisken_sayisi)==-1)  sy1=sayimi(aranacak1,strlen(aranacak1));
	else sy1 = deg_[arama(deg_,aranacak1,degisken_sayisi)].degeri;
	if(arama (deg_,aranacak2,degisken_sayisi)==-1)	   sy2=sayimi(aranacak2,strlen(aranacak2));
	else sy2 = deg_[arama(deg_,aranacak2,degisken_sayisi)].degeri;
	if(isaret2==0){
		if(dizi[isaret]=='<') {
		    if(sy1<sy2) return 1;
		    else return 0;
	    }
	    if(dizi[isaret]=='>') {
		    if(sy1>sy2) return 1;
		    else return 0;
	    }
   	}
	else {
		if(dizi[isaret]=='<'&& dizi[isaret2]=='=' ) {
		    if(sy1<=sy2) return 1;
		    else return 0;
	    }
        if(dizi[isaret]=='>'&& dizi[isaret2]=='=' ) {
		    if(sy1>=sy2) return 1;
		    else return 0;
	    }
    	if(dizi[isaret]=='='&& dizi[isaret2]=='=' ) {
		    if(sy1==sy2) return 1;
	    	else return 0;
	    }
	}	
}
int hicbir(char ad[],struct bul* deg_,int degisken_sayisi) {
	int islem2,sayi_1,sayi_2,sayi_3,alt_sinir=0, islem1,sonucumuz=0; 
	
	if(islemyap2(ad,alt_sinir)!=3) {
		char aranacak[40], aranacak2[40],aranacak3[40],aranacak4[40];
        int ust_sinir=strlen(ad),f=0,k=0,yeni_sinir,g=0;//isaretin yer
        while((islem2!=3 ||islem1!=3) &&ust_sinir>=0 && alt_sinir>=0 ){
        	f++;
            if(f==1) { 
            	if(k==0) ust_sinir-=1;
            	else ust_sinir=ust_sinir-strlen(aranacak)-1;
            	k++;
			    alt_sinir=islemyap2(ad,ust_sinir);
            	islem1=islemyap(ad,ust_sinir);
				for(int s=alt_sinir+1 ; ust_sinir+1>s;s++) {
            		aranacak[g]=ad[s];
            		g++;	 
				}
				aranacak[g] ='\0';
			    if (arama(deg_,aranacak,degisken_sayisi) ==-1) 	sayi_1=sayimi(aranacak,strlen(aranacak));
				else  sayi_1=deg_[arama(deg_,aranacak,degisken_sayisi)].degeri;
			    f++;
			    yeni_sinir=strlen(aranacak);
            }
            if(f==2) {
				ust_sinir=ust_sinir-yeni_sinir-1;
				alt_sinir=islemyap2(ad,ust_sinir);
				islem2=islemyap(ad,ust_sinir);
				g=0;
				for(int s=alt_sinir+1; ust_sinir+1>s;s++) {
            		aranacak2[g]=ad[s];
                    g++;	 
				}
				aranacak2[g] ='\0';
				if(islem1==3 && (strlen(ad)-strlen(aranacak)-strlen(aranacak2))==1) return sayi_1;
				yeni_sinir=strlen(aranacak2);
			    if (arama(deg_,aranacak2,degisken_sayisi) ==-1) sayi_2=sayimi(aranacak2,yeni_sinir);
				else sayi_2=deg_[arama(deg_,aranacak2,degisken_sayisi)].degeri;
			}
			if((islem1==4 || islem1==5 ) && (islem2==4 || islem2==5 ||islem2==3)) {
				if(islem1==5  && islem2==3) sonucumuz=sonucagit(sayi_1,sayi_2,5);
			    if(islem1==4  && islem2==4) sonucumuz=sonucagit(sayi_1,sayi_2,5)*(-1);
				if(islem1==5  && islem2==5) sonucumuz=sonucagit(sayi_1,sayi_2,5);
				if(islem1==4  && islem2==3) {
				 	if(sayi_1<sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4);
				    if(sayi_1>sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4)*(-1);
					if(sayi_1==sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,6);
				}
			    if((islem1==5 && islem2==4 ) ){
				 	if(sayi_1<sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4);
				    if(sayi_1>sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4)*(-1);
					if(sayi_1==sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,6);
				}
			    if((islem1==4 && islem2==5 ) ){
				    if(sayi_1>sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4);
				 	if(sayi_1<sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,4)*(-1);
					if(sayi_1==sayi_2) sonucumuz=sonucagit(sayi_1,sayi_2,6);
				}
				sayi_1=sonucumuz;
				f=1;
				islem2=islemyap(ad,ust_sinir);
			    if(islem2==3) {
				    islem1=islemyap(ad,ust_sinir);
				    
				 	if(islem2==3 && islem1==3) return sonucumuz;
			    }
			}
			else if((islem1==1  || islem1==2 )) {
				sonucumuz=sonucagit(sayi_2,sayi_1,islem1);
				sayi_1=sonucumuz;
				if(islem2==3) return sonucumuz;
				islem1=islem2;
				f=1;
			}
			else {
				if((islem1==5 || islem1==4) && (islem2==1 || islem2==2)) {
					ust_sinir=ust_sinir-yeni_sinir-1;
					alt_sinir=islemyap2(ad,ust_sinir);
					g=0;
					for(int s=alt_sinir+1; ust_sinir+1>s;s++) {
            			aranacak3[g]=ad[s];
            			g++;	 
				    }
					aranacak3[g] ='\0';
					yeni_sinir=strlen(aranacak3);
				    if (arama(deg_,aranacak3,degisken_sayisi) ==-1) sayi_3=sayimi(aranacak3,strlen(aranacak3));
				    else sayi_3=deg_[arama(deg_,aranacak3,degisken_sayisi)].degeri;
				    sonucumuz=sonucagit(sayi_2,sayi_3,islem2);
				    sayi_2=sonucumuz;
				    f=2;
				    islem2=islemyap(ad,ust_sinir);   
				}
			}
		}	
	}   
}
bool varmi(char dizi[]){
    	int k=0;
    	for(int i=0;i<strlen(dizi); i++) {
    		if((dizi[i]=='[') || (dizi[i]==']')) k++;	
		}
		if(k % 2== 0 && k>0) return true ;
		else return false;
}
int gitse(struct nosu* address,int adim,int g_s){
	for(int i=0;i<g_s; i++) if(adim==address[i].numarasi) return i;
	return 0;
}
int egerse(struct eger* eggerr,int adim,int eger_){
	for(int i=0;i<eger_+1; i++) if(adim==eggerr[i].numarasi) return i;
	return 0;
}
void menu(){
    printf("\tAsagidaki seceneklerden birini giriniz:\n\n");
	printf("\t\t1 - Dosya_1.txt dosyasini calistir\n");
	printf("\t\t2 - Dosya_2.txt dosyasini calistir\n");
	printf("\t\t3 - Dosya_3.txt dosyasini calistir\n");
	printf("\t\t4 - Dosya_4.txt dosyasini calistir\n");
	printf("\t\t5 - Dosya_5.txt dosyasini calistir\n");
	printf("\t\t6 - Dosya_6.txt dosyasini calistir\n");
	printf("\t\t7 - Dosya_7.txt dosyasini calistir\n");
	printf("\t\t8 - Dosya_8.txt dosyasini calistir\n");
	printf("\t\t9 - Cikis yap\n");
}
int main(){
	char kmt[6]={'h','i','c','b','i','r'};
    char   ad[500],deneme[40];
    int sirasayisi,gercek_sirasayisi=0,eger_=0,degisken_sayisi=0,egerde_islem=0,tr=0,kontrol=0,deger=1;
    struct bul deg_[30];
    struct nosu address[30];
    struct eger eggerr[5];
    		FILE* okuma;
    	menu();
        scanf("%d",&deger);
      while(!(deger>0 && deger<9)) scanf("%d",&deger);
        if(deger==1 ) okuma=fopen("dosya_1.txt","r");
        if(deger==2 ) okuma=fopen("dosya_2.txt","r");
        if(deger==3 ) okuma=fopen("dosya_3.txt","r");
        if(deger==4 ) okuma=fopen("dosya_4.txt","r");
        if(deger==5 ) okuma=fopen("dosya_5.txt","r");
        if(deger==6 ) okuma=fopen("dosya_6.txt","r");
        if(deger==7 ) okuma=fopen("dosya_7.txt","r");
	    if(deger==8 ) okuma=fopen("dosya_8.txt","r");
	
    	while(feof(okuma)==0){
    	int komut=0,adim,m=0,asd=0,dongu=0,t_=1,gecis=0;
    	if(kontrol != 1 ) fscanf(okuma,"%d %s\n",&sirasayisi,ad);
    	else  fscanf(okuma,"%s\n",ad);
    	 
    	gercek_sirasayisi++;
    	if(gercek_sirasayisi!=sirasayisi) {
			printf("\n%d.inci Sira numarasi hatali girilmistir",gercek_sirasayisi);
			return 0;
		}
		kontrol=0;
		if(1==sirasayisi) {
		    address[gercek_sirasayisi].komut=1;
		    address[gercek_sirasayisi].numarasi=sirasayisi;
		    if(hangisi(ad,strlen(ad))!=6) return 0;
	    	printf("Program Baslatildi\n");
        }
        if(hangisi(ad,strlen(ad))==4) {//egerrrrr
	   	    char ise_mi[40],gcc[30];
	    	address[gercek_sirasayisi].komut=6;
	    	address[gercek_sirasayisi].numarasi=sirasayisi;
	    	fscanf(okuma,"%s\n",&ad);
	    	fscanf(okuma,"%s\n",&ise_mi);
	    	strcpy(address[gercek_sirasayisi].data,ad);
	    	t_=egerde(deg_,ad,degisken_sayisi);
	    	if(egerde(deg_,ad,degisken_sayisi)!=1) m++;
	    		    fscanf(okuma,"%s\n",&ad);// komut
	    		    gecis=1;
	    		    if(t_==0){
	    		    	strcpy(gcc,ad); //  komut geciciye kopyalandý
	    		        fscanf(okuma,"%s\n",&deneme);// komutun kosacagý
	    	            fscanf(okuma,"%s\n",&ad);//degilse
	    	           	if(hangisi(ad,strlen(ad))==9){
	    	          	fscanf(okuma,"%s\n",&ad);// degilsenin komutu
	    	          	if(hangisi(ad,strlen(ad))==4){
	    	          		fscanf(okuma,"%s\n",&ad);
	    	          		t_=egerde(deg_,ad,degisken_sayisi);
	    	          		if(t_==0) {
	    	          			fscanf(okuma,"%s\n",&ad);
	    	          			fscanf(okuma,"%s\n",&ad);
	    	          			fscanf(okuma,"%s\n",&ad);
	    	          			if(hangisi(ad,strlen(ad))==9) fscanf(okuma,"%s\n",&ad);		  
							  }
							  else fscanf(okuma,"%s\n",&ad);
						  }
	    	          	gecis=1;
				    }
	    	    	else{
	    	    		gecis=0;
	    	    		if(sayimi(ad,strlen(ad))) sirasayisi--;
        		    	if(hangisi(ad,strlen(gcc))==1) strcpy(eggerr[eger_].komut,yaz);
	    	            if(hangisi(ad,strlen(gcc))==2) strcpy(eggerr[eger_].komut,git);
	    		    	strcpy(eggerr[eger_].data,deneme);
	    		    	strcpy(ad,gcc);
						}
						
			}
			
			strcpy(eggerr[eger_].komut,kmt);
			strcpy(eggerr[eger_].data,ad);
	    		    if(hangisi(ad,strlen(ad))==0) {
	    		    	strcpy(eggerr[eger_].data,ad);
	    		    	strcpy(eggerr[eger_].komut,kmt);
					}
	    		    if(hangisi(ad,strlen(ad))==1) strcpy(eggerr[eger_].komut,yaz);
	    		    if(hangisi(ad,strlen(ad))==2) strcpy(eggerr[eger_].komut,git);
	    			eggerr[eger_].numarasi=gercek_sirasayisi;
	    			egerde_islem++;
	    	        if(m>0 && hangisi(ad,strlen(ad))==2) dongu=1;
	    	        eger_++;
		} 
        if(hangisi(ad,strlen(ad))==0 && (komut==0 || asd==1)&& m==0) {
    		int h,i;
    		char yeni_dizi[40];
	            if(address[gercek_sirasayisi].komut !=6) address[gercek_sirasayisi].komut=0;
	    	    if(address[gercek_sirasayisi].komut !=6) strcpy(address[gercek_sirasayisi].data,ad);
	            h=hicbir(ad,deg_,degisken_sayisi);
	            for( i=0; i<strlen(ad);i++) {
	            	if(ad[i] !='=') yeni_dizi[i]=ad[i];
	            	else break;
		    	}
		    	yeni_dizi[i]='\0';
			    if(arama(deg_,yeni_dizi,degisken_sayisi) !=-1) 	deg_[arama(deg_,yeni_dizi,degisken_sayisi)].degeri=h;	
			    else {
	                strcpy(deg_[degisken_sayisi].degisken,yeni_dizi);
	                deg_[degisken_sayisi].degeri=h;
			        degisken_sayisi++;   
		        }
		    }
		    if(hangisi(ad,strlen(ad))==2 || (address[gercek_sirasayisi].komut==6 && hangisi(eggerr[eger_].komut,strlen(eggerr[eger_].komut))==2)) {// git
		    int search;
		    char yeni_dizi[40];
	        tr=1;
	        fscanf(okuma,"%d\n",&adim);
        	if(address[gercek_sirasayisi].komut !=6) address[gercek_sirasayisi].komut=4;
        	if(address[gercek_sirasayisi].komut ==6) eggerr[eger_].adim=adim;
        	search=gitse(address,adim,gercek_sirasayisi);
        	int p=adim,h,i,j=0;
        	while((address[search].numarasi != gercek_sirasayisi+1) && dongu==0){
        		int k=0;
        		printf(" ");
        		printf("\b");
        		int c;
        		switch(address[search].komut){
        			case 2:
        				if(arama(deg_,address[search].data,degisken_sayisi) !=-1)  scanf("%d",&deg_[arama(deg_,address[search].data,degisken_sayisi)].degeri);	
				        else if(varmi(address[search].data)==true) {
            	        char a[40];
		                char matris_ad[40],str[8],str2[8],matris_1[40],matris_2[40];
		                char yeni_dizi[40];
		                int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
		                for( i=0;i<strlen(address[search].data);i++) {
	        	            if(address[search].data[i] != '[') {
	                        	if(k==0) {
				                    matris_ad[j]=address[search].data[i];
		                            j++;
		                        }
                            } 
	                	    else {
			                    k++;
			                    if(k==1 && address[search].data[i] == '[') {
			                    	rt=i;//parantezin açýlma yeri
		    	                    for( l=i+1; l<strlen(address[search].data);l++) {
		    	    	                if(address[search].data[l]== ']') break;
		    	    	                matris_1[g]=address[search].data[l];
		    	    	                g++;
				                    }
				                    matris_1[g]='\0';
				                    pt=l;//köþeli parantezin kapanma yeri
				                    if(arama(deg_,matris_1,degisken_sayisi) !=-1) c=deg_[arama(deg_,matris_1,degisken_sayisi)].degeri;
			        	            sprintf(str,"%d",c);
						            for( r=0;r<strlen(str);r++) matris_ad[rt+1+r]=str[r];
					            	matris_ad[rt+1+r]=']';
						            i=pt+1;
		        	            }
		        	            if(i==strlen(address[search].data)-1) break;
		        	            if(k==1 && address[search].data[i]=='[') {
		    	                    for( l=i+1; l<strlen(address[search].data);l++) {
		    	    	                if(address[search+2].data[l]== ']') break;
		    	    	                matris_2[s]=address[search+2].data[l];
		    	    	                s++;
				                    }
					                matris_2[s]='\0';
			        	            if(arama(deg_,matris_2,degisken_sayisi) !=-1) c=deg_[arama(deg_,matris_2,degisken_sayisi)].degeri;
			        	            sprintf(str2,"%d",c);
			                    	for(int r=0;r<strlen(str2);r++) matris_ad[l-1]=str2[r];
				                }
		                    }
	                    }
	                    if(arama(deg_,matris_ad,degisken_sayisi) !=-1) scanf("%d",&deg_[arama(deg_,matris_ad,degisken_sayisi)].degeri);
				}
				break;
				case 0:	
					    h=hicbir(address[search].data,deg_,degisken_sayisi); 
					    for( i=0; i<strlen(address[search].data);i++) {
	                	    if(address[search].data[i] !='=') yeni_dizi[i]=address[search].data[i];
	                	    else break;
			            }
		        	    yeni_dizi[i]='\0';
			            if(arama(deg_,yeni_dizi,degisken_sayisi) !=-1) 	deg_[arama(deg_,yeni_dizi,degisken_sayisi)].degeri=h;
                        break;
                case 3:
				if(arama(deg_,address[search].data,degisken_sayisi) !=-1) printf("%d\n",deg_[arama(deg_,address[search].data,degisken_sayisi)].degeri);
	                    else if(address[search].data[0]=='"' && address[search].data[strlen(address[search].data)-1]=='"'){
		                    for(int i=1;i<strlen(address[search].data)-1; i++) 	printf("%c",address[search].data[i]);
		                    printf("\n");
			            }      
						else if(varmi(address[search].data)==true) { 
            	        char a[40];
            	        int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
		                char matris_addd[40],str3[8],str4[8],matris_3[40],matris_4[40];
		                char yeni_dizi[40];
                        for( i=0;i<strlen(address[search].data);i++) {
	                	   if(address[search].data[i] != '[') {
	            	            if(k==0) {
				                    matris_addd[j]=address[search].data[i];
		                            j++;
		                        }
                            } 
	        	            else {
			                    k++;
			                    if(k==1 &&  address[search].data[i] == '[') {
			                    	matris_addd[j]='[';
			        	            rt=i;//parantezin açýlma yeri
		    	                    for( l=i+1; l<strlen(address[search].data);l++) {
		    	    	                if(address[search].data[l]== ']') break;
		    	    	                matris_3[g]=address[search].data[l];
		    	    	                g++;
				                    }
				                    matris_3[g]='\0';
				                    pt=l;//köþeli parantezin kapanma yeri
				                    if(arama(deg_,matris_3,degisken_sayisi) != -1) c=deg_[arama(deg_,matris_3,degisken_sayisi)].degeri;
			        	            sprintf(str3,"%d",c);
			        	            
						            for( r=0;r<strlen(str3);r++) matris_addd[rt+1+r]=str3[r];
						            matris_addd[rt+1+r]=']';
						            i=pt+1;
		        	            }
		        	            if(i==strlen(address[search].data)-1) break;
		        	            if(k==1 && address[search].data[i]=='[') {
		    	                    for( l=i+1; l<strlen(address[search].data);l++) {
		    	    	                if(address[search].data[l]== ']') break;
		    	    	                matris_4[s]=address[search].data[l];
		    	    	                s++;
				                    }
					                matris_4[s]='\0';
			        	            if(arama(deg_,matris_4,degisken_sayisi) !=-1) c=deg_[arama(deg_,matris_4,degisken_sayisi)].degeri;
			        	            else c=sayimi(matris_4,strlen(matris_4));
									sprintf(str4,"%d",c);
			        	            for(int r=0;r<strlen(str4);r++) matris_addd[l-1]=str4[r];
					            }
		                    }
	                    }
	                    if(arama(deg_,matris_addd,degisken_sayisi) !=-1) printf("%d\n",deg_[arama(deg_,matris_addd,degisken_sayisi)].degeri);
                    }   
                    else {
				        int islem_mi;
				        char dizi_yeni[40];
			        	for(i=1;i<6;i++) if( islemyap(address[search].data,strlen(address[search].data))==i) islem_mi=1;
	                    if(islem_mi==1) {
	        	            dizi_yeni[0]='h';
	        	            dizi_yeni[1]='=';
	                    	for(i=2;i<strlen(address[search].data)+2;i++) dizi_yeni[i]=address[search].data[i-2];
	                    	dizi_yeni[i]='\0';
	                    	h=hicbir(dizi_yeni,deg_,degisken_sayisi);
	                        printf("%d\n",h);
		            	}
			        }
			        break;
			        case 6://eger
			        if(egerde(deg_,address[search].data,degisken_sayisi)==1) {
	                    	if(hangisi(eggerr[egerse(eggerr,address[search].numarasi,eger_)].komut,strlen(eggerr[egerse(eggerr,address[search].numarasi,eger_)].komut))==0) {
	                        	h=hicbir(eggerr[egerse(eggerr,address[search].numarasi,eger_)].data,deg_,degisken_sayisi);
	                	        for( i=0; i<strlen(  eggerr[egerse(eggerr,address[search].numarasi,eger_)].data );i++) {
	                            	if(eggerr[egerse(eggerr,address[search].numarasi,eger_)].data[i] !='=') yeni_dizi[i]=eggerr[egerse(eggerr,address[search].numarasi,eger_)].data[i];
	                	            else break;
			                    }
		        	            yeni_dizi[i]='\0';
			                    if(arama(deg_,yeni_dizi,degisken_sayisi) !=-1) 	deg_[arama(deg_,yeni_dizi,degisken_sayisi)].degeri=h;
					        }
	                        if(hangisi(eggerr[egerse(eggerr,address[search].numarasi,eger_)].komut,strlen(eggerr[egerse(eggerr,address[search].numarasi,eger_)].komut))==2 )  {
	                            if(gercek_sirasayisi==address[search].numarasi){
	                                search=gitse(address,p,gercek_sirasayisi);;
	                                adim=p-1;
	                                search--;
						        }
	                            else {
	                    	        adim=eggerr[egerse(eggerr,address[search].numarasi,eger_)].adim-1;
	                    	        search=gitse(address,adim,gercek_sirasayisi);
					        	}  
					        }
					        
					      //if(hangisi(egerse(tmp3,search->numarasi)->komut,strlen(egerse(tmp3,search->numarasi)->komut))==1 ) 
					    }
					    else {
						    if(hangisi(eggerr[egerse(eggerr,address[search].numarasi,eger_)].komut,strlen(eggerr[egerse(eggerr,address[search].numarasi,eger_)].komut))==2) {
						    }
						    else if(address[search].numarasi==gercek_sirasayisi) dongu=1;
				    	}
	                break;
	                 case 4: 
	                    search=gitse(address,p-1,gercek_sirasayisi);
	                    adim=p-1;
	                break;
                    default: return 0;
			}	
			       adim++;
			    	if(address[search].numarasi==gercek_sirasayisi) break;
			    	if(j==1) break;
			    	search++;
			}
		}
       if(hangisi(ad,strlen(ad	))==1)	 {//yaz
            
	        int islemmi=0,i,h,x=1;
	        char dizi_yeni[40],dizix[50];
	        if(address[gercek_sirasayisi].komut !=6) address[gercek_sirasayisi].komut=3;  
			address[gercek_sirasayisi].numarasi=gercek_sirasayisi; 	
			komut++;  
			
			if(address[gercek_sirasayisi].komut==6) { 
			int syss;
			if(gecis ==1) fscanf(okuma,"%s\n",ad); 
			else strcpy(ad,deneme);	
			fscanf(okuma,"%d",&syss);	
			if(syss==sirasayisi+1){
				kontrol=1;
				sirasayisi=syss;	
			}
			else fscanf(okuma,"%[^\n]s",dizix);
	        strcpy(eggerr[eger_].data,ad);
			if(egerde(deg_,address[gercek_sirasayisi].data,degisken_sayisi)==-1)  x=0;
		    } 
		    else fscanf(okuma,"%[^\n]s\n",ad); 
		    strcpy(address[gercek_sirasayisi].data,ad);
	        if(arama(deg_,ad,degisken_sayisi) !=-1) {
	            if(x==1) printf("%d\n",deg_[arama(deg_,ad,degisken_sayisi)].degeri);
	            continue;	
			    } 
	            if(x==0) continue;
	            for(i=1;i<6;i++) if( islemyap(ad,strlen(ad))==i) islemmi=1;
		    	if(islemmi==1) {
	        	    dizi_yeni[0]='h';
	            	dizi_yeni[1]='=';
	            	for(i=2;i<strlen(ad)+2;i++) dizi_yeni[i]=ad[i-2];
	        	    dizi_yeni[i]='\0';
	            	h=hicbir(dizi_yeni,deg_,degisken_sayisi);
	                printf("%d\n",h);
		    	}
		        else if(ad[0]=='"' && ad[strlen(ad)-1]=='"'){
		            for(int i=1;i<strlen(ad)-1; i++) 	printf("%c",ad[i]);
		            printf("\n");
			    }
				else if(varmi(ad)==true) { 
            	    char a[40];
            	    int i=0, k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
		            char matris_add[40],str[8],str2[8],matris_1[40],matris_2[40];
	        	    char yeni_dizi[40];
                    for(i=0;i<strlen(ad);i++) {
	        	       if(ad[i] != '[') {
	            	        if(k==0) {
				                matris_add[j]=ad[i];
		                        j++;
		                    }
                        } 
	            	    else{
			                k++;
			                if(k==1 && ad[i] == '[') {
			            	    rt=i;//parantezin açýlma yeri
		    	                for( l=i+1; l<strlen(ad);l++) {
		    	    	           if(ad[l]== ']') break;
		    	    	           matris_1[g]=ad[l];
		    	    	           g++;
				                }
				                matris_1[g]='\0';
				                pt=l;//köþeli parantezin kapanma yeri
				                if(arama(deg_,matris_1,degisken_sayisi) !=-1) c=deg_[arama(deg_,matris_1,degisken_sayisi)].degeri;
				                
			        	        sprintf(str,"%d",c);
			        	        matris_add[rt]='[';
						        for( r=0;r<strlen(str);r++) matris_add[rt+1+r]=str[r];
						        matris_add[rt+1+r]=']';
					    	    i=pt+1;
		            	    }
		        	        if(i==strlen(ad)-1) break;
		        	        if(k==1 && ad[i]=='[') {
		        	        	
		    	                for( l=i+1; l<strlen(ad);l++) {
		    	    	            if(ad[l]== ']') break;
		    	    	            matris_2[s]=ad[l];
		    	    	            s++;
				                }
					            matris_2[s]='\0';
					            
			            	    if(arama(deg_,matris_2,degisken_sayisi) != -1) c=deg_[arama(deg_,matris_2,degisken_sayisi)].degeri;
			            	    else c=sayimi(matris_2,strlen(matris_2));
		                        sprintf(str2,"%d",c);
			            	    matris_add[pt+1]='[';
			                	for(int r=0;r<strlen(str2);r++) matris_add[pt+r+2]=str2[r];
			                	matris_add[pt+2+strlen(str2)]=']';
					        }
		                }
	                }
	                if(arama(deg_,matris_add,degisken_sayisi) !=-1) printf("%d\n",deg_[arama(deg_,matris_add,degisken_sayisi)].degeri);
                }	
	        } 
	        if(hangisi(ad,strlen(ad))==8) {
			fscanf(okuma,"%s\n",&ad);
			if(varmi(ad)==1 ) { //matris
		    address[gercek_sirasayisi].komut=8;
			int j=0,k=0,tanimla=0,n=degisken_sayisi;
	        char matris_adi[40],matris_kapasite[40],str[8],str2[8],matris_kapasite2[40];
	        int kapasite=0,kapasite2=0,s=0,i,l;
	        for( i=0;i<strlen(ad);i++) {
	        	if(ad[i] != '[') {
	            	if(k==0) {
				        matris_adi[j]=ad[i];
		                j++;
		            }
                }
	        	else {
			        k++;
			        if(k==1 && ad[i] == '[') {
		    	        for( l=i+1; l<strlen(ad);l++) {
		    	    	    if(ad[l]== ']') break;
		    	    	    matris_kapasite[s]=ad[l];
		    	    	    s++;
				        }
					    matris_kapasite[s]='\0';
			        	kapasite=sayimi(matris_kapasite,strlen(matris_kapasite));
		        	}
		        	s=0;
		        	if(ad[l+1]=='[') {
		    	        for( l=i+1; l<strlen(ad);l++) {
		    	    	    if(ad[l]== ']') break;
		    	    	    matris_kapasite2[s]=ad[l];
		    	    	    s++;
				        }
				        tanimla=l;
					    matris_kapasite2[s]='\0';
			        	kapasite2=sayimi(matris_kapasite2,strlen(matris_kapasite2));
		        	}
		        }
	        }
	        int x=j;
	        if(k==1) {
		        for(int i=0;i<kapasite;i++) {
			        matris_adi[j]='[';
				    sprintf(str,"%d",i);
				    j++;
				    matris_adi[j]=str[0];
				    if(strlen(str)==2) {
					    j++;
					    matris_adi[j]=str[1];
				    }
				    j++;
            	    matris_adi[j]=']';
                    j++;
		            matris_adi[j]='\0';
	                degisken_sayisi++;
	                strcpy(deg_[degisken_sayisi-1].degisken,matris_adi);
                    j=x;
		        }
	        }
	        if(k==2) {
	        	for(int i=0;i<kapasite;i++) {
	        		for(int b=0;b<kapasite2;b++){
	        		    matris_adi[j]='[';
	        		    sprintf(str,"%d",i);
				        j++;
				        matris_adi[j]=str[0];
				        if(strlen(str)==2) {
					        j++;
					        matris_adi[j]=str[1];
				        }
				        j++;
            	        matris_adi[j]=']';
                        j++;
                        matris_adi[j]='[';
                        sprintf(str2,"%d",b);
				        j++;
				        matris_adi[j]=str2[0];
				        if(strlen(str2)==2) {
					       j++;
					        matris_adi[j]=str2[1];
				        }
				        j++;
            	        matris_adi[j]=']';
                        j++;
                        matris_adi[j]='\0';
	                    degisken_sayisi++;
			            strcpy(deg_[degisken_sayisi-1].degisken,matris_adi);
			            degisken_sayisi++;
                        j=x;
					}
				}
			}
		if(ad[tanimla+1]=='=') {
			int acma=0,kapama=0,virgul=0,sayac=0,w=0,v=0;
			
			for(int i=tanimla+2; i<strlen(ad); i++){
				if(ad[i]=='{') acma++;
			}
			if(acma==kapasite+1){
				for(int i=tanimla+2; i<strlen(ad); i++){
				if(ad[i]=='}') kapama++;
			}
			if(kapama==kapasite+1) {
			for(int i=tanimla+2; i<strlen(ad); i++){
				if(ad[i]==',') virgul++;
			}	
			if(virgul==((kapasite2-1)*kapasite+(kapasite-1))) {
			for(int i=tanimla+4; i<strlen(ad)-1; i++){
				for(int j=0; j<kapasite; j++){
					char gcc[10];
					for(int k=0; j<kapasite2; k++){
					   if(ad[i]== '}') break;
					   if(ad[i] != ','){
					   	gcc[v]=ad[i];
					   	v++;
					   	gcc[v]='\0';
					   	if(ad[i+1]==',' || ad[i+1]== '}'){
					   		deg_[n].degeri=sayimi(gcc,strlen(gcc));
					   		n+=2;
					   		v=0;
						   }
					   }
					   i++;
					}
					i+=3;
				}
			
			}	
			}
			}
			}
		}
		}
		
		}
	         if(hangisi(ad,strlen(ad	))==3){//gir
	         	char a[40];
		        char matris_ad[40],str[8],str2[8],matris_1[40],matris_2[40];
		        char yeni_dizi[40];
	    	    int i=1,k=0,j=0,s=0,l=0,g=0,c,rt,x=0,pt=0,r;
			    address[gercek_sirasayisi].komut=2;
	            komut++;
	            fscanf(okuma,"%s\n",ad);
	            strcpy(address[gercek_sirasayisi].data,ad);
	            address[gercek_sirasayisi].numarasi=gercek_sirasayisi; 	
                if(arama(deg_,ad,degisken_sayisi) !=-1) 	scanf("%d",&deg_[arama(deg_,ad,degisken_sayisi)].degeri);	                
                else if(varmi(ad)==true) {
            	    for( i=0;i<strlen(ad);i++) {
	        	        if(ad[i] != '[') {
	                    	if(k==0) {
				                matris_ad[j]=ad[i];
		                        j++;
		                    } 
                        } 
	        	        else{
			                k++;
			                if(k==1 && ad[i] == '[') {
			        	        rt=i;//parantezin açýlma yeri
		    	                for( l=i+1; l<strlen(ad);l++) {
		    	    	           if(ad[l]== ']') break;
		    	    	           matris_1[g]=ad[l];
		    	    	           g++;
				                }
				                matris_1[g]='\0';
				                pt=l;//köþeli parantezin kapanma yeri
				                if(arama(deg_,matris_1,degisken_sayisi) !=-1) c=deg_[arama(deg_,matris_1,degisken_sayisi)].degeri;
			        	        sprintf(str,"%d",c);
			        	        
						        for( r=0;r<strlen(str);r++) matris_ad[rt+1+r]=str[r];
						        matris_ad[rt+1+r]=']';
						        i=pt+1;
						        
		        	        }
		        	        if(i==strlen(ad)-1) break;
		        	        if(k==1 && ad[i]=='[') {
		    	            for( l=i+1; l<strlen(ad);l++) {
		    	    	        if(ad[l]== ']') break;
		    	    	        matris_2[s]=ad[l];
		    	    	        s++;
				            }
					        matris_2[s]='\0';
			        	    if(arama(deg_,matris_2,degisken_sayisi) !=-1) c=deg_[arama(deg_,matris_2,degisken_sayisi)].degeri;
			        	    sprintf(str2,"%d",c);
			        	    for(int r=0;r<strlen(str2);r++) matris_ad[l-1]=str2[r];
				    	}
		            }
	            }
	            if(arama(deg_,matris_ad,degisken_sayisi) !=-1) {
	            	
	            	scanf("%d",&deg_[arama(deg_,matris_ad,degisken_sayisi)].degeri);
				}
            }
            else {
			    scanf("%d",&deg_[degisken_sayisi].degeri);
			    strcpy(deg_[degisken_sayisi].degisken,ad);
			    degisken_sayisi++;
            }
	        strcpy(address[gercek_sirasayisi].data,ad);
			 }
	         if(hangisi(ad,strlen(ad))==5)	 {//bitti
		        address[gercek_sirasayisi].komut=5;
		        address[gercek_sirasayisi].numarasi=gercek_sirasayisi;
                printf("Program Bitirildi\n");
    	    }
	}
	getch();
	system("cls");
	fclose(okuma);
	
}
