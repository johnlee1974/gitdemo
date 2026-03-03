#include "b25v_base___com_000.h"

//------<999> 依存関係見直し要

//------- Z   ------
extern ULONG vspmaxh;                                       //vspmaxのホールドタイプ
extern ULONG vstath;                                        //VSTATのホールドタイプ
extern ULONG pstath;                                        //pstathのホールドタイプ
extern ULONG tsdsver1h;                                     //SDS動作時の速度異常検出(強制減
extern ULONG vt59rgh;                                       //ﾗﾝｸ別故障ｺﾝﾄﾛｰﾙﾌﾗｸﾞﾎｰﾙﾄﾞﾀｲﾌﾟ
extern ULONG p900;                                          //同期階床
extern ULONG hhbsmf;                                        //段取り運転
extern const ULONG ivaspdcd; // ｽﾋﾟｰﾄﾞｺｰﾄﾞ
extern ULONG hutspd;                                        //UCMP制動力試験速度45m/min化
extern ULONG v65rgy;                                        //ALP 50%検出


//------- U   ------

//------- Q   ------

//------- l   ------

//------- D   ------

//------<999> 見直し要

/****************************************************************************
* NAME              =b25v6a.cpp											 	*
* FUNCTION          =従ソフト部											 	*
* NOTE              =                                                    *
* AUTHOR            =                                                    *
* DATE              =2023.11.13                                          *
* ORIGINAL          =(FD No.)                                            *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
* b14z_base01_com(m31)_001 以降適用                                      *
*  <001>:△001:                           2023.10.30[T.Hatori]           *
*  <002>:△002:                           20xx.xx.xx[]                   *
*  <003>:△003:                           20xx.xx.xx[]                   *
*  <004>:△004:                           20xx.xx.xx[]                   *
*  <005>:△005:                           20xx.xx.xx[]                   *
*  <006>:△006:                           20xx.xx.xx[]                   *
*  <007>:△007:                           20xx.xx.xx[]                   *
*  <008>:△008:                           20xx.xx.xx[]                   *
*  <009>:△009:                           20xx.xx.xx[]                   *
*  <010>:△010:                           20xx.xx.xx[]                   *
* COPYRIGHT (C) HITACHI,LTD. 2023 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/
#pragma inline(vabs, r2roots, r3roots, vabssign)
/************************************************************************/
/*     シーケンス(v6a00p)                                               */
/************************************************************************/
extern "C" ULONG v6a00p(void);
ULONG v6a00p(void){
//ユーザー用ワーク
register ULONG ulwk0;
register ULONG ulwk1,ulwk2;
register LONG lwk0;
ULONG wlwk3;
//*****@st_vacccd64~vtopcmd
ulwk0 = v10h;
if (!v10hx){
	if (ulwk0){
		vacccd64 = 0;
		vspmaxh = 0;
		vstath = 0;
		pstath = 0;
		vdccst64 = 0;
		vdccat64 = 0;
		vdccas64 = 0;
		*vdccw = 0;
		vtopcmd = 0;
//
		vhlverr[0] = 0;					//herios予兆
		vhlverr[1] = 0;					//herios予兆
		vnmlstp = 0;					//herios予兆
		vstopck = 0;					//ﾘｾｯﾄ処理追加	2014.08.18[D.Chen]
		tsdsver1h = 0;					//<024> FLS200mm時誤検出対策 2018.04.25[K.Sakai]
		vt59rgh = 0;					//<024> FLS200mm時誤検出対策 2018.04.25[K.Sakai]
		v1214tm = 0;					//ﾉﾛﾉﾛ時間計測 H.Sakamoto
	}
//*****@ed_vacccd64~vtopcmd
//*****@st_p900k~td900pd
	if (ulwk0){
		if (!zv49h || (zv49h && (h10sys(1) & BIT6))){
			p900st = p900;
		}
		if (zv49h && !(h10sys(1) & BIT6)){
			p900 = p900k;
			p900st = p900;
			pstat |= BIT1;
		}
		if (!(hvsys(3) & BIT2)){				//ﾉｯﾁﾚｽ制御
			padln = (LONG)*hpadln1;
		}
		else {							//ﾉｯﾁﾚｽ制御
			padln = 10;
			vpadlnsa = 10;
			vdc1tmx = 256;
			vdc1tmxw = 256;
			vdc2tmx = 256;
			vdc2tmxw = 256;
			vac2tmx = 0;
			vspmax = 0;
			vspmaxp = 0;
			vspmaxpw = 0;
			vdc2w3 = 0;
			vdc2spw = 0;
			vdc1w3 = 0;
			vdc1spw = 0;
			vpadscw = 0;
			vdc3tmx = 0;
			vpadlnsb = 0;
			vpadlnsc = 0;
			vpadlnsd = 0;
			vpadlnse = 0;
			vpadlnsf = 0;
			vac2w1 = 0;
			vpadsdw = 0;
			vachcm = 0;
			vsphcm = 0;
			vhybcosd = 0;				//HYB ｽﾄｯﾌﾟﾚｽ制御
			vbatov1 = 0;
			vbatov2 = 0;
			*vbatdrvt = cvbatdrvt.cmt(0);
			vbvstat7 = 0;
			vspmaxv = 0;	//可変速ﾃﾞﾊﾞｲｽｲﾆｼｬﾗｲｽﾞ
			vachcmv = 0;	//可変速ﾃﾞﾊﾞｲｽｲﾆｼｬﾗｲｽﾞ
		}
		vstat |= BIT0;
		varvtm = 0xFF;
		vflsae = 0;
		p900pdck = 0;
		tp900pd = 0;
		vtrqset = 0;
	}
}
//*****@ed_p900k~td900pd	//debug 削除 D.Chen 2014.06.24
if(v10h && !(xvfml & BIT31) && !vflsae){	//C03 追加 2014.05.20[D.Chen] SAEﾏｲｸﾛ対策(HVF-0364)
	vflsae2 = 0;
}
//*****@st_vstath,patath
if (v10hx){
	vstath = vstath | vstat;
	pstath = pstath | pstat;
	tsdsver1h = tsdsver1h | tsdsver1;		//<024> FLS200mm時誤検出対策 2018.04.25[K.Sakai]
	vt59rgh = vt59rgh | vt59rg[0];			//<024> FLS200mm時誤検出対策 2018.04.25[K.Sakai]
}
//*****@st_vstath,patath
//*****@st_v10hx
v10hx = v10h;
//*****@st_v10hx
//*****@st_vspdcd~pcmpln1
if (!v10h){
	vspdcd = 0;
	vspmod = 0;
	v92 = 0;
	vdclat64 = 0;
	vdclas64 = 0;
	vdclst64 = 0;
	vlstat = 0;
	vtopcmd1 = 0;
	vstat = 0;
	if ((!hhbsmf && !zv44eqs40) || !v10c){
		pstat = 0;
	}
	vwdcct = 0;
	varvtm = 0;
	pcmpln1 = 0;
}
//*****@ed_vspdcd~pcmpln1
//*****@st_pcmpln~vsddcctm
if (!v10h){
	pcmpln = 0;
	*vsddcctm = 0;
	vh06spcmd = 0;	//HYB ｽﾄｯﾌﾟﾚｽ制御
	*vhybsdtm = 0;	//HYB ｽﾄｯﾌﾟﾚｽ制御
}
//*****@ed_pcmpln~vsddcctm
//*****@st_p900,p900st,pstat
ulwk0 = za10h & zv49h & (!(p900k == 0) *-1);
ulwk1 = ulwk0 & (!(h10sys(1) & BIT6) -1) & v10h & (!(pstat & BIT1) * -1);
if (ulwk1){
	p900 = p900k;
	p900st = p900k;
	pstat |= BIT1; 
}
//
ulwk1 = ulwk0 & (!(h10sys(1) & BIT6) * -1) & ~v10h & ~v102fh;
if (ulwk1){
	p900 = p900k;
	p900st = p900k;
}
//*****@ed_p900,p900st,pstat
//*****@st_vspcmd
if (!v10h && !v10l && !v10c && !v16){
	vspcmd = 0;
}
//*****@ed_vspcmd
//*****@st_ppschk
if (!v10l){
	ppschk = 0;
}
//*****@ed_ppschk
//*****@st_vaspdcd //可変速ドライブシステム
ulwk0 = (h10sys(5) & BIT4) && (!(tvver&BIT31))  && (vzaspdup);
vspdupa = ulwk0 || ((vspdupa) && v10h);//可変速許可
ulwk1 = (vamtrcd == 0xB5) || (vamtrcd == 0x9B) || (vamtrcd == 0x9D) || (vamtrcd == 0x9F) || (vamtrcd == 0xA1);		//産機ﾏｼﾝ_Ph3適用
if(vspdupa){//可変速システム
if(ivaspdcd == 0x04){	//定格60m/min→75m/min→90m/min
	if((va15wl || va85wh) || (hspcdlm <= 4)){//60m/min M44速度制限条件
		vaspdcd = (ULONG)ivaspdcd;
		vspdupf = 0;
		vspdupgr = 0;
		hvvidcmd = hidcmd1;
		svvidg = hsvvidg0;		//可変速弱め界磁定数スペック化
	}else if((!va15wl && va30wl) || (va70wh && !va85wh) || (hspcdlm <= 5)){//75m/min M44速度制限条件
		vaspdcd = (ULONG)ivaspdcd + 1 ;
		if(v10h){
			vspdupf = (ULONG)-1;
			vspdupgr = 1;
		}else{
			vspdupf = 0;
			vspdupgr = 0;
		}
		if(!v60w && v15b && ulwk1){		//可変速弱め界磁定数スペック化
			hvvidcmd = hvvidcmd1;		//可変速弱め界磁定数スペック化
			svvidg = hsvvidg1;		//可変速弱め界磁定数スペック化
		}
		else{
			hvvidcmd = hidcmd1;
			svvidg = hsvvidg0;		//可変速弱め界磁定数スペック化
		}
	}else if(!va15wl && !va30wl && !va70wh && !va85wh){//90m/min
		vaspdcd = (ULONG)ivaspdcd + 2;
		if(v10h){
			vspdupf = (ULONG)-1;
			vspdupgr = 2;
		}else{
			vspdupf = 0;
			vspdupgr = 0;
		}
		if(!v60w && v15b && ulwk1){		//可変速弱め界磁定数スペック化
			hvvidcmd = hvvidcmd2;		//可変速弱め界磁定数スペック化
			svvidg = hsvvidg2;		//可変速弱め界磁定数スペック化
		}
		else{
			hvvidcmd = hidcmd1;
			svvidg = hsvvidg0;		//可変速弱め界磁定数スペック化
		}
	}
}else{	//45m/min→60m/min，90m/min→105m/min
	if((va15wl || va85wh) || (hspcdlm <= ivaspdcd)){//定格速度 44速度制限条件
		vaspdcd = (ULONG)ivaspdcd;
		vspdupf = 0;
		vspdupgr = 0;
	}else{//(定格速度+15m/min)
		vaspdcd = (ULONG)ivaspdcd + 1;
		if(v10h){
			vspdupf = (ULONG)-1;
			vspdupgr = 1;
		}else{
			vspdupf = 0;
			vspdupgr = 0;
		}
	}
	hvvidcmd = hidcmd1;
	svvidg = hsvvidg0;		//可変速弱め界磁定数スペック化
}
}else{
	if(!(h10sys(5) & BIT7)){	//可変速ﾉｯﾁﾚｽではh1aにて展開
//		vaspdcd = (ULONG)ivaspdcd;	//↓<024>UCMP試験速度45m/min対応 2018.04.25[K.Sakai]
		if(!(utstvupf && hutspd)){
			vaspdcd = (ULONG)ivaspdcd;
		}else{
			vaspdcd = 45/15;	//45m/min
		}							//↑<024>
	}
	hvvidcmd = hidcmd1;
	svvidg = hsvvidg0;		//可変速弱め界磁定数スペック化
	vspdupf = 0;
	vspdupgr = 0;
}
if (!(*(tvhec + 1) & BIT31)){
    hrvset = vaspdcd * 15 - ispadj;
	hspcmmax = vaspdcd * h15spcmd;
}
//*****@ed_vaspdcd
ulwk0 = 0;
if(hvsys(4) & BIT1){
	ulwk1 = (ULONG)((!((vreofstf==0xA5A5A5A5) && v100a))-1);
	ulwk2 = (ULONG)((!((vreofstf==0x96969696) && v100a))-1);
	if(va70wh & (v11 | ulwk1)){
		ulwk0 = 0xA5A5A5A5;
	}
	else if(va30wl & (v12 | ulwk2)){
		ulwk0 = 0x96969696;
	}
	else{
		ulwk0 = 0;
	}
}
vreofstf = ulwk0;
vspdupa2 = (vzaspdup) || ((vspdupa2) && v10h);  //<035> <D074>
if((h10sys(5) & BIT7) && (hvsys(3) & BIT2) && v10){
	if(!dxvvw){					//官庁検査対応
		ulwk0 = v65rgy;
	}else{
		if((0 <= (LONG)v65rgy) && ((LONG)v65rgy <= 10)){
			ulwk0 = 0;
		}else{
			if((15 <= (LONG)v65rgy) && ((LONG)v65rgy <= 35)){
				ulwk0 = 25;
			}else{
				if((65 <= (LONG)v65rgy) && ((LONG)v65rgy <= 85)){
					ulwk0 = 75;
				}else{
					if((90 <= (LONG)v65rgy) && ((LONG)v65rgy <= 110)){
						ulwk0 = 100;
					}else{
						ulwk0 = v65rgy;
					}
				}
			}
		}
	}
    if(v65rgyw_testmode == 0xA5A55A5A){     //<035> <D047>
        ulwk0 = v65rgyw_test;
    }
	v65rgyw = ulwk0;
	if(v11){
		if((LONG)v65rgyw < (LONG)h65rgw1u){
			lwk0 = (LONG)ivaspdcd * (LONG)h15spcmd;
		}else{
			if((LONG)v65rgyw <= (LONG)h65rgw2u){
				if(!(h65rgw1u == h65rgw2u)){
					lwk0 = (LONG)(ivaspdcd * h15spcmd) + ((LONG)hvvnspc * (LONG)h15spcmd * ((LONG)v65rgyw - (LONG)h65rgw1u) / ((LONG)h65rgw2u - (LONG)h65rgw1u));
				}else{
					lwk0 = (LONG)(ivaspdcd + hvvnspc) * (LONG)h15spcmd;
				}
			}else{
				if((LONG)v65rgyw < (LONG)h65rgw3u){
					lwk0 = (LONG)(ivaspdcd + hvvnspc) * (LONG)h15spcmd;
				}else{
					if((LONG)v65rgyw <= (LONG)h65rgw4u){
						if(!(h65rgw3u == h65rgw4u)){
							lwk0 = (LONG)(ivaspdcd * h15spcmd) + ((LONG)hvvnspc * (LONG)h15spcmd * ((LONG)h65rgw4u - (LONG)v65rgyw) / ((LONG)h65rgw4u - (LONG)h65rgw3u));
						}else{
							lwk0 = (LONG)(ivaspdcd + hvvnspc) * (LONG)h15spcmd;
						}
					}else{
						lwk0 = (LONG)ivaspdcd * (LONG)h15spcmd;
					}
				}
			}
		}
	}else if(v12){
		if((LONG)v65rgyw < (LONG)h65rgw1d){
			lwk0 = (LONG)ivaspdcd * (LONG)h15spcmd;
		}else{
			if((LONG)v65rgyw <= (LONG)h65rgw2d){
				if(!(h65rgw1d == h65rgw2d)){
					lwk0 = (LONG)(ivaspdcd * h15spcmd) + ((LONG)hvvnspc * (LONG)h15spcmd * ((LONG)v65rgyw - (LONG)h65rgw1d) / ((LONG)h65rgw2d - (LONG)h65rgw1d));
				}else{
					lwk0 = (LONG)(ivaspdcd + hvvnspc) * (LONG)h15spcmd;
				}
			}else{
				if((LONG)v65rgyw < (LONG)h65rgw3d){
					lwk0 = (LONG)(ivaspdcd + hvvnspc) * (LONG)h15spcmd;
				}else{
					if((LONG)v65rgyw <= (LONG)h65rgw4d){
						if(!(h65rgw3d == h65rgw4d)){
							lwk0 = (LONG)(ivaspdcd * h15spcmd) + ((LONG)hvvnspc * (LONG)h15spcmd * ((LONG)h65rgw4d - (LONG)v65rgyw) / ((LONG)h65rgw4d - (LONG)h65rgw3d));
						}else{
							lwk0 = (LONG)(ivaspdcd + hvvnspc) * (LONG)h15spcmd;
						}
					}else{
						lwk0 = (LONG)ivaspdcd * (LONG)h15spcmd;
					}
				}
			}
		}
	}
//	if((lwk0 >= ((LONG)ivaspdcd * (LONG)h15spcmd)) && (lwk0 <= (8 * (LONG)h15spcmd)) && !(tvver & BIT31)){	//TCD=C1検出時の可変速禁止条件追加	//<035> <D074>
	if((lwk0 >= ((LONG)ivaspdcd * (LONG)h15spcmd)) && (lwk0 <= (8 * (LONG)h15spcmd)) && !(tvver & BIT31) && (vspdupa2)){
		vspcmdv = lwk0;
	}else{
		vspcmdv = (LONG)ivaspdcd * (LONG)h15spcmd;
	}
	ulwk1 = (ULONG)vspcmdv * 10 / 1024;
	vspcmdvd = rbtd1s(&ulwk1);	//積載別最高速度の10進表示
}
ulwk0 = v10h & (ULONG)((!((LONG)vspcmd > (LONG)(*(ivspdupv+2))))-1);//90m/min～
ulwk1 = v10h & ~ulwk0 & (ULONG)((!((LONG)vspcmd > (LONG)(*(ivspdupv+1))))-1);//45m/min～90m/min
ulwk2 = v10h & (ULONG)((!((LONG)vspcmdv > (LONG)hvvrrspd))-1);//可変速高速モード
vspdup1 = ulwk0;
vspdup2 = ulwk1;
vspdupi = ulwk2;

//↓<035> <D011>

ulwk0 = !((hvsys(0) & BIT1) && (v60asr) && (v10h))-1;
//if(v65rgyw >= hrid65rg2){       //<035> <D047>
if(v65rgy >= hrid65rg2){       //<037>(4) <D116>
	ulwk1 = 0xFFFFFFFF;
}
//else if((v65rgyw >= hrid65rg1) && !(vstat & BIT7)){     //<035> <D047>
else if((v65rgy >= hrid65rg1) && !(vstat & BIT7)){     //<037>(4) <D116>
	ulwk1 = 0xFFFFFFFF;
}
else{
	ulwk1 = 0;		
}
vridmskb = ulwk0 & ulwk1;

//↑<035> <D011>

return (ULONG)-1;
}
