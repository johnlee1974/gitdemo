#include "b25v_base___com_000.h"

#include "../../B25z_base00/inc/b25z_base00_ra1_000.h"
#include "../../B25z_base00/inc/b25z_base00_ra2_000.h"
#include "../../B25z_base00/inc/b25z_base00_ras_000.h"
#include "../../B25z_base00/inc/b25z_base00_rabk_000.h"
#include "../../B25z_base00/inc/b25z_base00_sp1_000.h"
#include "../../B25z_base00/inc/b25z_base00_sp2_000.h"

//------<999> 依存関係見直し要

//------- Z   ------
extern ULONG vspmxh;                                        //vspmxのホールドタイプ
extern ULONG hlmspd15;                                      //端階低速運転速度15m/min
extern ULONG hflspat;                                       
extern ULONG xsds1u;                                        //スローダウンスイッチ入力
extern ULONG xsds1d;                                        //スローダウンスイッチ入力
extern ULONG xhcpcd1;                                       //HYB盤1ﾁｮｯﾊﾟｺｰﾄﾞ

extern ULONG vspmxh;                                        //vspmxのホールドタイプ
extern ULONG xhcpcd1;                                       //HYB盤1ﾁｮｯﾊﾟｺｰﾄﾞ
extern ULONG vspmxh;                                        //vspmxのホールドタイプ
extern ULONG hstshc3;                                       

extern ULONG hstshc1;                                       
extern ULONG hstshc2;                                       
extern ULONG xhcpcd1;                                       //HYB盤1ﾁｮｯﾊﾟｺｰﾄﾞ
//------- U   ------

//------- Q   ------

//------- l   ------

//------- D   ------

//------<999> 見直し要

/****************************************************************************
* NAME              =b25v6b.cpp											 	*
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
extern ULONG rv6b20ls(void);
extern ULONG rv6d70ls(void);
extern ULONG rv6c00ls(void);
extern ULONG rv6c10ls(void);
extern ULONG rv6c20ls(void);
extern ULONG rv6c30ls(void);
extern ULONG rv6c40ls(void);
extern ULONG rv6c50ls(void);
extern ULONG rv6d10ls(void);
extern ULONG rv6d20ls(void);
extern ULONG rv6d30ls(void);
extern ULONG rv6d40ls(void);
extern ULONG rv6d50ls(void);
extern ULONG rv6d60ls(void);
extern ULONG rv6dc0ls(void);
extern ULONG rv6dd0ls(void);
extern ULONG rv6de0ls(void);
extern ULONG rv6df0ls(void);

/************************************************************************/
/*     シーケンス(v6b00p)                                               */
/************************************************************************/
ULONG (*const iv6bjmt[])() = {rv6c00ls, rv6c10ls, rv6c20ls, rv6c30ls, rv6c40ls, rv6c50ls,
                             rv6d10ls, rv6d20ls, rv6d30ls, rv6d40ls, rv6d50ls, rv6d60ls,
                             rv6dc0ls, rv6dd0ls, rv6de0ls, rv6df0ls};
extern "C" ULONG v6b00p(void);
ULONG v6b00p(void){
//ユーザー用ワーク
register ULONG ulwk0;
//*****@st_v6b20l
rv6b20ls();
//*****@ed_v6b20l
//*****@st_v6b70l
rv6d70ls();
//*****@ed_v6b70l
(*iv6bjmt[vspmod])(); 
//*****@ed_v6df0l
if(!v15b || (vspcmd == 0)){	//ﾌﾞﾚｰｷ動作か速度指令零時にvspdfb記録ﾌﾗｸﾞｸﾘｱ
	hspdfbstf = 0;
	hhdcstopf =0;
	hdcstopwk =hdcstop;
}
//*****@st_herios
if (cv97at.dmt()){
	if ((vstat & BIT12) && (vstat & BIT14) && (vstat & BIT15)){
		vnmlstp = (ULONG)-1;
	}
	ulwk0 = ~vnmlstp & ~v10h & (!(xvfml & BIT31) -1) & (!(vstat & BIT12) *-1) & ((!(vstat & BIT14) -1) | (!(vstat & BIT15) -1));
	if (ulwk0){
		vhlverr[0] |= BIT4;
		vhlverr[1] = p900;
	}
	ulwk0 = ~vnmlstp & ~v10h & (!(xvfml & BIT31) -1) & (!(vstat & BIT12) -1) & ((!(vstat & BIT14) *-1) | (!(vstat & BIT15) *-1));
	if (ulwk0){
		vhlverr[0] |= BIT5;
		vhlverr[1] = p900;
	}
	/*TB3-0010 ﾉﾛﾉﾛ時間計測 H.Sakamoto*/
	if((vstat & BIT12) && !(vstat & BIT14)){
		v1214tm += 1;
	}
}
//*****@ed_herios
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6b20l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*		     <1>:						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6b20l)                                               */
/************************************************************************/
ULONG rv6b20ls(void){
//ユーザー用ワーク
register ULONG ulwk0;
ULONG ulwk1,ulwk2,ulwk3,ulwk4; 
LONG lwk4;

//*****@st_vibattry					//HYB ｽﾄｯﾌﾟﾚｽﾊﾞｯﾃﾘ電流計算
if (hhyb & BIT31){
	if (vtrqcmd & BIT15){
		lwk4 = (LONG)(0xFFFF0000 | vtrqcmd);
	}
	else{
		lwk4 = (LONG)vtrqcmd;
	}
	if (v12){
		lwk4 = 0 - lwk4;
	}
	if (varopecd && h15spcmd){													//モータ出力計算
		vpmotor = (LONG)(lwk4/*vtrqcmd*/ * (LONG)hratetrq / 0x2000 * 2 * (LONG)varopecd * 1000 / (LONG)hshevd * 15 * (LONG)vspcmd / (LONG)h15spcmd / 60);
	}
	else{
		vpmotor = 0;
	}
//
	if (vpmotor >= 0){															//直流部電流計算
		if (hetamtr && hetainv && hetacs){ 
			vpdcurnt = (LONG)((vpmotor * 1000 / (LONG)hetamtr * 1000 / (LONG)hetainv) + ((LONG)hpcntsce / (LONG)hetacs));
		}
		else{
			vpdcurnt = 0;
		}
	}
	else{
		if (hetacs){ 
			vpdcurnt = (LONG)((vpmotor * (LONG)hetamtr / 1000 * (LONG)hetainv / 1000) + ((LONG)hpcntsce / (LONG)hetacs));
		}
		else{
			vpdcurnt = 0;
		}
	}
//
	if (vpdcurnt >= 0){
		if (hetacher && hetabatt){												//バッテリ出力電力 	
			vpbattry = (LONG)(vpdcurnt * 1000 / (LONG)hetacher * 1000 / (LONG)hetabatt);
		}
		else{
			vpbattry = 0;
		}
	}
	else{
		vpbattry = (LONG)(vpdcurnt * (LONG)hetacher / 1000 * (LONG)hetabatt / 1000);
	}
//
	if (hebattry){
		vibattry = (LONG)(vpbattry / (LONG)hebattry);							//バッテリ電流 
	}
	else{
		vibattry = 0;
	}
}
//*****@ed_vibattry
//*****@st_vspdcd,padln,vstat,vspmxh
ulwk0 = (!(vstat & BIT1) -1) & (!(vstat & BIT6) * -1);
if (ulwk0){											//ﾉｯﾁﾚｽ制御
	if (vspmod == 0x2){
		if ((vacccd64 + hacccd64 * hcmtmx / hac1tmx) >= hacccd64){
 			vachcm = hacccd64;
		}
		else {
			vachcm = vacccd64 + hacccd64 * hcmtmx / hac1tmx;
		}
		vac2tmx = vachcm * hac2tmx / hacccd64;
		vsphcm = vspcmd + vachcm * hcmtmx / 0x40 / 10;
		vspmax = vsphcm + vachcm * vac2tmx / 0x2 / 0x40 / 10;
		vac2tm = vacccd64 * hac2tmx / hacccd64;
		vac2sp = vacccd64 * vac2tm / 0x2 / 0x40 /10;
		if(h10sys(5) & BIT7){
			if(vacccd64 >= hacccd64){
				vachcmv = hacccd64;
			}else{
				vachcmv = vacccd64;
			}
			vspmaxv = vspcmd + (vachcmv * vac2tmx / 0x2 / 0x40 / 10) - 0x10;
		}
	}
	else {
		vac2tmx = hac2tmx;
 		vsphcm = vspcmd + hacccd64 * hcmtmx / 0x40 / 10;
		vspmax = vsphcm + hacccd64 * vac2tmx / 0x2 / 0x40 / 10;
		vac2tm = hac2tmx;
		vac2sp = hacccd64 * vac2tm / 0x2 / 0x40 /10;
		if(h10sys(5) & BIT7){
			vspmaxv = vspcmd + (hacccd64 * vac2tmx / 0x2 / 0x40 / 10) - 0x10;
		}
 	}
} 
if (ulwk0 && !(hvsys(3) & BIT2)){							//ﾉｯﾁﾚｽ制御
	vspdcd = (ULONG)(((vspcmd + (LONG)hac2sp) / (LONG)h15spcmd) + 1);
}
if (ulwk0 && (hvsys(3) & BIT2)){							//ﾉｯﾁﾚｽ制御
	vspdcd = (ULONG)((vspcmd + (LONG)vac2sp) / (LONG)h15spcmd);
}
ulwk1 = 0;
ulwk3 = 0;
if (ulwk0 && !(hhyb & BIT31)){				//HYB ｽﾄｯﾌﾟﾚｽ制御
	if (!(vspdcd >= vaspcd)){
		ulwk0 = (ULONG)-1;
	}
	if (vspdcd >= vaspcd){
		ulwk1 = vaspcd;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;
	}
}
if (ulwk0){
	if (!(vspdcd >= vaspdcd)){
		ulwk0 = (ULONG)-1;
	}
	if (vspdcd >= vaspdcd){
		ulwk1 = vaspdcd;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;	//NO;
	}
}
if (ulwk0){
	if (!(vspdcd >= hspcdlm)){
		ulwk0 = (ULONG)-1;
	}
	if (vspdcd >= hspcdlm){
		ulwk1 = hspcdlm;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;
	}
}
if (ulwk0){
	if (!zv49h || (zv49h && !(vspdcd >= h49splm))){
		ulwk0 = (ULONG)-1;
	}
	if (zv49h && (vspdcd >= h49splm)){
		ulwk1 = h49splm;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;
	}
}
if (ulwk0){
	if ((h10sys(5) & BIT7) && (hvsys(3) & BIT2) && (vspmaxv >= vspcmdv)){
		ulwk1 = vspdcd;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;
	}
}
if (ulwk0){
	if((dxvvlm || zvvvlm) && (vspdcd >= ivaspdcd)){
		ulwk1 = ivaspdcd;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;
	}
}
//
if (ulwk0){									//HYB ｽﾄｯﾌﾟﾚｽ加速中停電処理
	if (!(hhyb & BIT31) || !vh97bp){
		ulwk0 = (ULONG)-1;	//YES;
	}
	if ((hhyb & BIT31) && vh97bp){
		if (!vh06spcmd && (vspcmd > vspcmdlm)){
			ulwk1 = vspdcd;
			ulwk3 = (ULONG)-1;	//YES;
			ulwk0 = 0;	//NO;
			vstat |= BIT7;
			vspmod = 4;
		}			
		else if (!vh06spcmd && (vspcmd <= vspcmdlm) && (vspcmd >= vspcmdlma)){
			ulwk1 = vspdcd;
			ulwk3 = (ULONG)-1;	//YES;
			ulwk0 = 0;	//NO;
			vstat |= BIT7;
			vspmod = 4;
			vbvstat7 = (ULONG)-1;
		}
		else if (!vh06spcmd && (vspcmdlm >= h15spcmd)){
			if ((vspcmd > h15spcmd/2) && (vspcmd > (vspcmdlm - hac2sp))){ 
				ulwk1 = vspdcd;
				ulwk3 = (ULONG)-1;	//YES;
				ulwk0 = 0;	//NO;
				vbvstat7 = (ULONG)-1;
			}
		}
		else if (vh06spcmd && (vspdcd >= 0x1)){
			ulwk1 = 0x1;
			ulwk3 = (ULONG)-1;	//YES;
			ulwk0 = 0;	//NO;
		}				
		else{
			ulwk0 = (ULONG)-1;
		}		 		 
	}
}
//
ulwk2 = 0;
ulwk4 = 0;
if (ulwk0 && !(hhyb & BIT31)){		//HYB ｽﾄｯﾌﾟﾚｽ(S.ALPｼｰｹﾝｽ除外)
	if (!zvasalp){
		ulwk0 = (ULONG)-1;
	}
	if ((!(hvsys(3) & BIT2) && (zvasalp && !(vspdcd >= 0x1))) || (zvasalp && (vspdcd >= 0x1))){		//ﾉｯﾁﾚｽ制御
		ulwk1 = 0x1;
		ulwk3 = (ULONG)-1;
		ulwk0 = 0;
	}
}
if (ulwk0){
	if (!v92 && !zv92h && !zv92){
		ulwk0 = (ULONG)-1;
	}
	if ((!v92 && !zv92h && zv92) || (!v92 && zv92h) || v92){
		ulwk2 = vspdcd;
		ulwk4 = (ULONG)-1;
		ulwk0 = 0;
	}
}
if (ulwk0){
	if (!(hvsys(3) & BIT2)){						//ﾉｯﾁﾚｽ制御
		padln = (LONG)*(hpadln1 + vspdcd);
	}
	vstat |= BIT4;
}
if (ulwk3){
	vspdcd = ulwk1;
	vspmxh = vspdcd;
	vstat |= BIT6;
}
if (ulwk4){
	vspmxh = ulwk2;
	vstat |= BIT6;
}
//*****@ed_vspdcd,padln,vstat,vspmxh
//*****@st_vtopcmd1
if (!(vstat & BIT8)){
	vtopcmd1 = vspcmd;
}
//*****@ed_vtopcmd1
//*****@st_vtopcmd
if (!(vstat & BIT7) && (vspcmd > vtopcmd)){
	vtopcmd = vspcmd;
}
//*****@ed_vtopcmd
//*****@st_vstat
if (zv92){
	vstat |= BIT3;
}
//*****@ed_vstat
//*****@st_vspmod
ulwk0 = (~zv15ka | hsae1) & zarsc & (zv92k | v90saw);
if (ulwk0 && (vspcmd >= (LONG)h15spcmd)){
	vspmod = 0xC;
}
//*****@ed_vspmod
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6c00l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =												 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:							 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.					 *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                        *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6c00l)												*/
/************************************************************************/
//extern "C" ULONG rv6c00ls(void);
ULONG rv6c00ls(void){
//ユーザー用ワーク
register ULONG ulwk0;
ULONG ulwk1,ulwk2;  

//*****@st_v6c00l
//*****@st_vspmod,v49cmd,vspcmd
ulwk0 = 0;
if (v10h && v60asr && cv10ct.dmt()){
	if (!zv49h){
		vspmod = 0x1;
	}
	else{
		ulwk0 =(ULONG)-1;
	}
}
ulwk1 = ulwk0 & v100;
ulwk2 = ulwk0 & ~v100 & ((z44eqc & vxdz) | (~z44eqc &(!(p300 == p900k) -1) & zv92 & vxdz));
if (ulwk1){
//	v49cmd = h15spcmd;			//<004> 中間階出発の99E時にSDSで減速処理 2014.11.27 [N.Takayama]
//	if((!(!(v12 & xsds1d) && !(v11 & xsds1u)))-1){		//<024>99E速度15m/min固定 2018.04.25 [K.Sakai]
	if((!(!(v12 & xsds1d) && !(v11 & xsds1u)))-1 || (hflspat & hlmspd15)){
		v49cmd = h15spcmd;
	}
	else{
		v49cmd = h10spcmd;
	}
}
if (ulwk2){
	v49cmd = h02spcmd;
}
if (ulwk2 && (p900dzps > (LONG)h49lln)){
	vspmod = 0xA;
	vstopck |= BIT8;	//C03 追加 2014.05.20[D.Chen]n 着床方法ﾁｪｯｸ(debug用)
}
if (ulwk0){

	
	vspcmd += (((LONG)v49cmd - vspcmd) * (LONG)h49cnst) / 0x10000;

}
ulwk1 = ulwk0 & (!(pstat & BIT3) -1) & (!(vstat & BIT1) * -1);
if (ulwk1 && !ctvtrqft.dmt()){
	vspmod = 0x1;
}
//*****@ed_vspmod,v49cmd,vspcmd
//*****@ed_v6c00l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6c10l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>: 						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6c10l)                                               */
/************************************************************************/
ULONG rv6c10ls(void){
//ユーザー用ワーク

//*****@st_v6c10l
//*****@st_vstat,vspdcd,padln,vspmod
// v6c10l
if (v10h && v60asr){
	if(!(hvsys(3) & BIT2)){                      	//ﾉｯﾁﾚｽ制御
		vspdcd = 1;
		padln = hpadln1[1];
	}
	vstat |= BIT1;
	vspmod = 2;
	p900pdx = 0;
	p900pdmx = 0;							//<micro停止>
	pderflg1 = 0;
	pderflg2 = 0;
	pderflg3 = 0;							//<micro停止>
	p900pdmsx = 0;							//直引きmicro停止>
//
	if ((hhyb & BIT31) && vh97bp && (vspcmdlm < h15spcmd) && (xhcpcd1 & BIT4)){		//HYB ｽﾄｯﾌﾟﾚｽ制御
		vh06spcmd = (ULONG)-1;
	}
}
//*****@ed_vstat,vspdcd,padln,vspmod
//*****@ed_v6c10l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6c20l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*		     <1>:   						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6c20l)                                               */
/************************************************************************/
ULONG rv6c20ls(void){
//ユーザー用ワーク
register ULONG ulwk0;
ULONG ulwk1;

ulwk0 = 0;
ulwk1 = 0;
//*****@st_v6c20l
// v6c20l
//*****@st_vacccd64
vacccd64 += (LONG)hac1cmd;
//*****@ed_vacccd64
//*****@st_vspcmd
vspcmd  += (vacccd64 / 0x40);
//*****@ed_vspcmd
//*****@st_vacccd64,vstat,vspmod
if (vacccd64 > (LONG)hacccd64){
	vacccd64 = (LONG)hacccd64;
	vstat |= BIT2;
	vspmod = 0x3;
}
else{
	ulwk0 = (!(vstat & BIT6) -1);
	if (ulwk0){
		if(!(hvsys(3) & BIT2)){	
			if (zv49h && (vspdcd < 6)){
				ulwk0 = (ULONG)-1;
			}
			if ((zv49h && !(vspdcd < 6)) || !zv49h){
				ulwk1 = (ULONG)-1;
				ulwk0 = 0;
			}
			if (ulwk0){
				ulwk0 = (!(vspcmd > (LONG)(((h15spcmd + h15spcmd * vspdcd) * hac1sp) / (hac1sp + hac2sp))) -1);
			}
			if (ulwk1){
				ulwk1 = (!(vspcmd > (LONG)(((h15spcmd * vspdcd) * hac1sp) / (hac1sp + hac2sp))) -1);
			}
			if (ulwk0 || ulwk1){
				vstat |= BIT2;
				vspmod = 3;
			}
		}
		else{
			vstat |= BIT2;
			vspmod = 3;
		}
	}
}
//*****@ed_vacccd64,vstat,vspmod
//*****@ed_v6c20l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6c30l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*		     <1>: 						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6c30l)                                               */
/************************************************************************/
ULONG rv6c30ls(void){
//ユーザー用ワーク
register ULONG ulwk0;
ULONG ulwk1,ulwk2; 

//*****@st_v6c30l
// v6c30l
//*****@st_vspmod,pdlnpl,vstat
ulwk0 = (!(vstat & BIT6) -1) & (!(hvsys(3) & BIT2) * -1) & (!((vspdcd * h15spcmd) >= hac2sp) -1);
ulwk1 = (!(vstat & BIT6) -1) & (!(hvsys(3) & BIT2) * -1) & (!((vspdcd * h15spcmd) >= hac2sp) * -1);
ulwk2 = ulwk0 & (!(vspcmd >= (LONG)(vspdcd * h15spcmd - hac2sp)) -1);
if (ulwk1 || ulwk2){
	vspmod = 4;
	pdlnpl = *(hpadln2 + vspdcd);
	vstat |= BIT5;
}
if ((!(vstat & BIT6) -1) && (!(hvsys(3) & BIT2) -1)){ 
	vspmod = 4;
	pdlnpl = *(hpadln2 + vspdcd);
	vstat |= BIT5;
}
//*****@ed_vspmod,pdlnpl,vstat
//*****@st_vspcmd
vspcmd += (vacccd64 / 0x40);
//*****@ed_vspcmd
//*****@ed_v6c30l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6c40l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*		     <1>: 						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6c40l)                                               */
/************************************************************************/
ULONG rv6c40ls(void){
//ユーザー用ワーク
register ULONG ulwk0;
ULONG ulwk1,ulwk2,ulwk3;

//*****@st_v6c40l
//*****@st_vacccd64,vspcmd,vstat
ulwk0 = (!((LONG)hac2cmd > vacccd64) * -1) & (!(hvsys(3) & BIT2) * -1) & (!(vspcmd > (LONG)(vspmxh * h15spcmd)) * -1);				//ﾉｯﾁﾚｽ制御
ulwk1 = ((!((LONG)hac2cmd > vacccd64) * -1) & (!(hvsys(3) & BIT2) * -1) & (!(vspcmd > (LONG)(vspmxh * h15spcmd)) -1)) | (!((LONG)hac2cmd > vacccd64) -1);	//ﾉｯﾁﾚｽ制御
ulwk1 |= ulwk0 & (!(vspcmd > (LONG)hspcmmax) -1);														//ﾉｯﾁﾚｽ制御
ulwk0 &= (!(vspcmd > (LONG)hspcmmax) * -1);
ulwk2 = (!((LONG)hac2cmd > vacccd64) * -1) & (!(hvsys(3) & BIT2) -1) & (!(vspcmd > (LONG)hspcmmax) * -1) & (!(vstat & BIT7) *-1);	//ﾉｯﾁﾚｽ制御 HYB ｽﾄｯﾌﾟﾚｽなまし中止
ulwk3 = (!((LONG)hac2cmd > vacccd64) * -1) & (!(hvsys(3) & BIT2) -1) & (!(vspcmd > (LONG)hspcmmax) -1);								//ﾉｯﾁﾚｽ制御
ulwk2 = ulwk2 | ((!((LONG)hac2cmd > vacccd64) * -1) & (!(hvsys(3) & BIT2) -1) & (!(h10sys(5) & BIT7) -1) & (!(vspcmd > vspcmdv) * -1) & (!(vstat & BIT7) *-1));
ulwk3 = ulwk3 | ((!((LONG)hac2cmd > vacccd64) * -1) & (!(hvsys(3) & BIT2) -1) & (!(h10sys(5) & BIT7) -1) & (!(vspcmd > vspcmdv) -1));
//
if (ulwk0 || ulwk2){
	vacccd64 -=(LONG)hac2cmd;
	vspcmd += (vacccd64 / 0x40);
}
if (ulwk1 || ulwk3){
	vacccd64 = 0;
	vstat |= BIT7;
	if (!(hvsys(3) & BIT2) && (vspcmd > (LONG)(vspmxh * h15spcmd))){
		vspcmd = (LONG)(vspmxh * h15spcmd);
	}
	if (vspcmd >= (LONG)hspcmmax){
		vspcmd = (LONG)hspcmmax;
	}
	if((h10sys(5) & BIT7) && (hvsys(3) & BIT2) && (vspcmd >= vspcmdv)){
		vspcmd = vspcmdv;
	}
}
//
if ((hhyb & BIT31) && (hvsys(3) & BIT2)){		
	if (vh97bp && !(xhcpcd1 & BIT4)){
		if ((vspcmd > (vspcmdlm + 0x10)) && (vspcmd >= h15spcmd)){
			vstat |= BIT7;
			vacccd64 = 0;
			vspcmd = vspcmd - hsdsdcc3;
		}
	}
	if (vh97bp && (xhcpcd1 & BIT4) && cvstat7tm1.dmt()){	
		if (hhyb & BIT2){ 
			if (((xvhybid1 + xvhybid2) > (LONG)hibatlim) && (vspcmd >= h15spcmd)){
				vbatovc2 += 1;
				vbatov2 += vabssign((xvhybid1 + xvhybid2),(LONG)hibatlim);
				if (vbatovc2 > 100){
					vbatov2 = vbatov2 / (LONG)hibatlim;
					vspcmdb2 = vbatov2 * vspcmd / 100;
					vspcmd = vspcmd - vspcmdb2;
					vbatovc2 = 0;
					vbatov2 = 0;
				}					
			}
			else{
				vbatovc2 = 0;
				vbatov2 = 0;
			}				
		}
		else{
			if ((xvhybid1 > (LONG)hibatlim) && (vspcmd >= h15spcmd)){
				vbatovc2 += 1;
				vbatov2 += vabssign(xvhybid1,(LONG)hibatlim);
				if (vbatovc2 > 100){
					vbatov2 = vbatov2 / (LONG)hibatlim;
					vspcmdb2 = vbatov2 * vspcmd / 100;
					vspcmd = vspcmd - vspcmdb2;
					vbatovc2 = 0;
					vbatov2 = 0;
				}		
			}
			else{
				vbatovc2 = 0;
				vbatov2 = 0;
			}	
		}
		if (vspcmd < h15spcmd){
			vspcmd = h15spcmd;
			vh06spcmd = (ULONG)-1;
		}
	}
}	
//*****@ed_vacccd64,vspcmd,vstat
//*****@ed_v6c40l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6c50l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:												 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6c50l)                                               */
/************************************************************************/
ULONG rv6c50ls(void){
//ユーザー用ワーク

//ループ変数

//*****@st_v6c40l

//*****@ed_v6c40l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6d10l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:												 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d10l)                                               */
/************************************************************************/
ULONG rv6d10ls(void){
//ユーザー用ワーク
register LONG lwk1;
ULONG ulwk0;

//*****@st_v6d10l
//*****@st_vdccw[0]
vdccw[0] = vhdccsp + (vdccas64 / 0x40) - vdccst64;
//*****@ed_vdccw[0]
//*****@st_vdccat64
vdccat64 += (LONG)hdc1cmd;
vdccat64 = vdccat64 & 0xFFFF;
//*****@ed_vdccat64
//*****@st_vdccas64
vdccas64 += vdccat64;
//*****@ed_vdccas64
//*****@st_vdccst64
vdccst64 += (LONG)hdcccd64 / 0x40;
//*****@ed_vdccst64
//*****@st_vstat
lwk1 = 0;
lwk1 = (LONG)((vtopcmd1 * hdc2spw) / (hdc1sp + hdc2spw)); 
if (vspcmd <= lwk1){

	vstat |= BIT10;
}
//*****@ed_vstat
//*****@st_vstat,vsmod,vspcmd,vdcccd64
if ((vstat & BIT10) || (!(vstat & BIT10) && !(*(vdccw + 1) > *vdccw))){
	vstat |= BIT9;
	vspmod = 0x7;
	vspcmd = vdcspd - *vdccw;
	vdcccd64 = vdccat64;
}
//*****@ed_vstat,vsmod,vspcmd,vdcccd64
//*****@st_vdccw[1],vspcmd
ulwk0 = 0;	//NO;
lwk1 = 0;	//NO;
if (!(vstat & BIT10) && (*(vdccw + 1) > *vdccw)){
	*(vdccw + 1) = *vdccw;
	lwk1 = vdcspd - *vdccw;
	ulwk0 = (ULONG)-1;
}
if (ulwk0 && (lwk1 < vtopcmd)){
	vspcmd = lwk1;
}
//*****@ed_vdccw[1],vspcmd
//*****@ed_v6d10l
return (ULONG)-1;	//YES;
}

/*************************************************************************
* NAME              =b14v6d20l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:vdc2djk演算式変更 2003.02.05 古橋               *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d20l)                                               */
/************************************************************************/
ULONG rv6d20ls(void){
//ユーザー用ワーク

//*****@st_v6d20l
//*****@st_vspcmd
if (vdcspd >= *vdccw){
	vspcmd = vdcspd - *vdccw;
}
if (!(vdcspd >= *vdccw)){
	vspcmd = vdcspd;
}
//*****@ed_vspcmd
//*****@st_vstat,vspmod
if (vspcmd < (LONG)hdc2spw){
	vstat |= BIT11;
	vspmod = 0x8;
}
//*****@ed_vstat,vspmod
//*****@st_vdccw[0]
if (vstat & BIT10){
	*vdccw = 0;
}
//*****@ed_vdccw[0]
//*****@st_vdc2djk
if (vspmxh >= 0x6){
	vdc2djk = hdc2djk;
}
else{
	vdc2djk = (hdc2djk * 0x20) / 0x20;
}
//*****@ed_vdc2djk
//*****@st_vspcmdw
vspcmdw = vspcmd;
//*****@st_vspcmdw
//*****@ed_v6d20l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6d30l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:												 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d30l)                                               */
/************************************************************************/
ULONG rv6d30ls(void){
//ユーザー用ワーク
register LONG lwk0;
LONG  lwk2,lwk3;
//ループ変数

//*****@sd_v6d30l
//*****@st_v3rp,v3rp3,v3rq,v3rq2
lwk0 = 0;
lwk2 = 0;
if (vdccln >= 0x44C){
	lwk2 = 0x44C;
}
if (!(vdccln >= 0x44C) && (vdccln < 0)){
	lwk2 = 1;
}
if (!(vdccln >= 0x44C) && !(vdccln < 0)){
	lwk2 = vdccln;
}
v3rp = (LONG)vdc2djk * (LONG)ispmin / (LONG)hvconst;
v3rp3 = (((v3rp * v3rp) / 0x100) * v3rp) / 0x100;
//	ispmin=1m/minによる下位桁残し
//ここから
v3rq = ((3 * lwk2 * (LONG)vdc2djk) / 2) & 0xFFFFFF00;
v3rq2 = (v3rq / 0x100) * (v3rq / 0x100);
//*****@ed_v3rp,v3rp3,v3rq,v3rq2
//*****@st_v3rq2p3
lwk2 = v3rq2 + v3rp3;
lwk0 = r2roots(((ULONG)lwk2) * 9);
v3rq2p3 = (((lwk0) & 0x0000FFFF) * 0x100) / 3;
//ここまで
//*****@ed_v3rq2p3
//*****@st_v3ru
lwk0 = 0;
lwk2 = 0;
lwk3 = 0;
if ((v3rq + v3rq2p3) < 0x3FD00BFF){
	lwk2 = v3rq + v3rq2p3;
	lwk0 = (LONG)r3roots((ULONG)lwk2);
	v3ru = lwk0;
}
else{
	lwk3 = (v3rq + v3rq2p3) / 0x8;
	lwk0 = (LONG)r3roots((ULONG)lwk3);
	v3ru = lwk0 * 2;
}
//*****@ed_v3ru
//*****@st_v3rv
lwk0 = 0;
lwk2 = 0;
lwk3 = 0;
if ((v3rq2p3 - v3rq) < 0x3FD00BFF){
	lwk2 = v3rq2p3 - v3rq;
	lwk0 = (LONG)r3roots((ULONG)lwk2);
	v3rv = lwk0;
}
else{
	lwk3 = (v3rq2p3 - v3rq) / 0x8;
	lwk0 = (LONG)r3roots((ULONG)lwk3);
	v3rv = lwk0 * 2;
}
//*****@ed_v3rv
//*****@st_vdc2tm
vdc2tm = (v3ru - v3rv) & 0xFFFF;
//*****@ed_vc2tm
//*****@st_vdccw[0]
if (*vdccw < 0){
	*vdccw = 0;
}
else{
	if (*vdccw >= (LONG)idccw){
		*vdccw = *vdccw - (LONG)idccw;
	}
	else{
		*vdccw = *vdccw;
	}
}
//*****@ed_vdccw[0]
//*****@st_vspmod,vstat,vspcmd,vspcmdw
lwk0 = (((LONG)hvconst * vdc2tm * vdc2tm / (LONG)vdc2djk) + (LONG)ispmin) & 0xFFFF;
if (lwk0 >= *vdccw){
	lwk0 = lwk0 - *vdccw;
}
else{
	lwk0 = 0;
}
if (lwk0 <= (LONG)ispmin){
	vspmod = 0xA;
	vstat |= BIT12;
}
else{
	vspcmd = (vspcmdw + lwk0) / 2; 
	vspcmdw = vspcmd;
}
//*****@ed_vspmod,vstat,vspcmd,vspcmdw
//*****@ed_v6d30l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6d40l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:												 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d40l)                                               */
/************************************************************************/
ULONG rv6d40ls(void){
//ユーザー用ワーク

//ループ変数


//*****@st_v6d40l

//*****@ed_v6d40l
return (ULONG)-1;
}

/****************************************************************************
* NAME              =b14v6d50l.cpp										 	*
* FUNCTION          =従ソフト部											 	*
* NOTE              =													 	*
* AUTHOR            =M.Furuhashi										 	*
* DATE              =2002.05.28											 	*
* ORIGINAL          =(FD No.)											 	*
* HISTORY           =<000>:変更内容 年(西暦2桁).月(2桁).日(2桁) [作成者名]	*
*					 <003>着床ﾚﾍﾞﾙﾊﾞﾗﾂｷ改善　07.06.06 深田					*
*					 <013>:OU-08G対応 2009.06.25 深田	*
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   	*
*****************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d50l)                                               */
/************************************************************************/
ULONG rv6d50ls(void){
//ユーザー用ワーク
register ULONG ulwk0,ulwk1;
LONG  lwk0; 

//*****@st_v6d50l
//*****@st_vspcmd,vstat,vspmod,v10h,vabrans
lwk0 = 0;
ulwk1 = 0;
//if (zv49h || (!zv49h && (vstat & BIT14))){		//C03 追加 2014.05.20[D.Chen] 増速しない中間階出発,通常着床処理
if ((zv49h && !(pstat & BIT3)) || (vstat & BIT14)){
//
//*****@st_hdcstopwk						//着床ﾚﾍﾞﾙﾊﾞﾗﾂｷ改善
//hdcstop切替回路
	if(!hspdfbstf && (vstat & BIT14) && !(vspcmd == 0)){	//vspdfb記録ﾌﾗｸﾞ

		if (vspdfb & BIT15){
			lwk0 = (LONG)(0xFFFF0000 | vspdfb);
		}
		else{
			lwk0 = (LONG)vspdfb;
		}
//↓<017>(3) 2017.06.28 [N.Takayama]
//		vspdfbst = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        if(hspgain){
		    vspdfbst = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        }
        else{
		    vspdfbst = 0;		//vspdfb記録(m/min)
        }
//↑<017>(3) 2017.06.28 [N.Takayama]
		hspdfbstf = (ULONG)-1;
	}

	if((!(hvsys(2) & BIT1) -1) && (!hhdcstopf && (vstat & BIT14))){		//製品用
	if(!(hvsys(3) & BIT7) *-1){			//直引きﾏｲｸﾛ停止処理時無効
		hhdcstopf = (ULONG)-1;
		      if(vspdfbst > (14*(LONG)ispmin/15)){		//ispmin=1.5m/minの時
			hdcstopwk =hdcstop;		//そのまま
		}else if(vspdfbst > (12*(LONG)ispmin/15)){		//ispmin=1.5m/minの時
			hdcstopwk =3*hdcstop/2;		//1.5倍
		}else if(vspdfbst > (10*(LONG)ispmin/15)){		//ispmin=1.5m/minの時
			hdcstopwk =2*hdcstop;		//2倍
		}else if(vspdfbst > ( 8*(LONG)ispmin/15)){		//ispmin=1.5m/minの時
			hdcstopwk =5*hdcstop/2;		//2.5倍
		}else{							//	        それ以下    3.0倍
			hdcstopwk =3*hdcstop;		//3.0倍
		}		
	}else{
		hhdcstopf = (ULONG)-1;						//直引きﾏｲｸﾛ停止処理

		if(v11 && !v12){
		if((vspdfbrs22 > 3*(LONG)ispmin)){
			if(vspdfbst > (20*(LONG)ispmin/10)){			//ispmin=1.0m/minの時、vspdfbst=2.0m/min以上2分の1
				hdcstopwk =hdcstop/2;		//1/2.0倍
			}else if(vspdfbst > (15*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.5m/min以上1.5分の1
				hdcstopwk =2*hdcstop/3;		//1/1.5倍
			}else if(vspdfbst > (10*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.0m/min以上1.0倍
				hdcstopwk =hdcstop;		//1.0倍
			}else if(vspdfbst > ( 5*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=0.5m/min以上2.0倍
				hdcstopwk =2*hdcstop;		//2.0倍
			}else{							//			        それ以下    2.5倍
				hdcstopwk =5*hdcstop/2;		//2.5倍
			}
		}else{
			if(vspdfbst > (20*(LONG)ispmin/10)){			//ispmin=1.0m/minの時、vspdfbst=2.0m/min以上4分の1
				hdcstopwk =hdcstop/4;		//1/4.0倍
			}else if(vspdfbst > (15*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.5m/min以上3分の1
				hdcstopwk =hdcstop/3;		//1/3.0倍
			}else if(vspdfbst > (10*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.0m/min以上2分の1
				hdcstopwk =hdcstop/2;		//1/2.0倍
			}else if(vspdfbst > ( 5*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=0.5m/min以上1.0倍
				hdcstopwk =hdcstop;		//1.0倍
			}else{							//			        それ以下    1.5倍
				hdcstopwk =3*hdcstop/2;		//1.5倍
			}
		}
		}
		if(!v11 && v12){
		if( vspdfbrs21 >  3*(LONG)ispmin){
			if(vspdfbst > (20*(LONG)ispmin/10)){			//ispmin=1.0m/minの時、vspdfbst=2.0m/min以上2分の1
				hdcstopwk =hdcstop/2;		//1/2.0倍
			}else if(vspdfbst > (15*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.5m/min以上1.5分の1
				hdcstopwk =2*hdcstop/3;		//1/1.5倍
			}else if(vspdfbst > (10*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.0m/min以上1.0倍
				hdcstopwk =hdcstop;		//1.0倍
			}else if(vspdfbst > ( 5*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=0.5m/min以上2.0倍
				hdcstopwk =2*hdcstop;		//2.0倍
			}else{							//			        それ以下    2.5倍
				hdcstopwk =5*hdcstop/2;	//2.5倍
			}
		}else{
			if(vspdfbst > (20*(LONG)ispmin/10)){			//ispmin=1.0m/minの時、vspdfbst=2.0m/min以上4分の1
				hdcstopwk =hdcstop/4;		//1/4.0倍
			}else if(vspdfbst > (15*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.5m/min以上3分の1
				hdcstopwk =hdcstop/3;		//1/3.0倍
			}else if(vspdfbst > (10*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=1.0m/min以上2分の1
				hdcstopwk =hdcstop/2;		//1/2.0倍
			}else if(vspdfbst > ( 5*(LONG)ispmin/10)){		//ispmin=1.0m/minの時、vspdfbst=0.5m/min以上1.0倍
				hdcstopwk =hdcstop;		//1.0倍
			}else{							//			        それ以下    1.5倍
				hdcstopwk =3*hdcstop/2;		//1.5倍
			}
		}	
		}
		}
	}
	lwk0 = vspcmd - (vspcmd / (LONG)hdcstopwk);
	ulwk1 = (ULONG)-1;
}
//*****@ed_hdcstopwk
if (ulwk1){
	if (lwk0 <= (LONG)hdcstopwk){						//着床ﾚﾍﾞﾙﾊﾞﾗﾂｷ改善
		vspcmd = 0;
		vstat |= BIT15;
		vspmod = 0;
		v10h = 0;
		vabrans = (ULONG)-1;
//
		if (!vtrqset){
			vtrqset = (ULONG)-1;
			if (v11){
				if (v65rg < 0xA){
					h65rg45a[0] = (0 - vtrqcmd) & 0xFFFF;
					h65rg45b[0] = (0 - vtrqcmd) & 0xFFFF;
				}
				if ((h65rg45(0) != 0) && (v65rg > 0x5A)){
					hwctrqua = (vtrqcmd + h65rg45(0)) / v65rg;
				}
			}
			if (v12){
				if (v65rg < 0xA){
					h65rg45a[1] = (0 - vtrqcmd) & 0xFFFF;
					h65rg45b[1] = (0 - vtrqcmd) & 0xFFFF;
				}
				if ((h65rg45(1) != 0) && (v65rg > 0x5A)){
					hwctrqda = (vtrqcmd + h65rg45(1)) / v65rg;
				}
			}
			ulwk0 = (vabssign(h65rg45b[0],h65rg45(0)) + vabssign(h65rg45b[1],h65rg45(1))) / 2;
			h65rgdfa = (0 - ulwk0) & 0xFFFF;
		}
//		
	}
	else{
		vspcmd = lwk0;
	}
}
//*****@st_vspcmd,vstat,vspmod,v10h,vabrans
//*****@ed_v6d50l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6d60l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:												 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d60l)                                               */
/************************************************************************/
ULONG rv6d60ls(void){
//ユーザー用ワーク

//*****@st_v6d60l

//*****@ed_v6d60l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6d70l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>: 						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6d70l)                                               */
/************************************************************************/
ULONG rv6d70ls(void){
//ユーザー用ワーク
register LONG lwk1;
ULONG ulwk0,ulwk1,ulwk2,ulwk3,ulwk4,ulwk5;
LONG  lwk0,lwk2,lwk3,lwk4,lwk5,lwk6,lwk7,lwk8;
double udwk0;						//C03 追加 2014.05.20[D.Chen]
//*****@st_v6d70l
// v6d70l
//*****@st_vdclw[0],vdclat64,vdclas64,vdclst64,vlstat,vspcmd,vdcccd64,vdclw[1]
ulwk0 = v92 & (!(vlstat & BIT2) * -1) & (!(vlstat & BIT0) -1) & (!(vlstat & BIT1) -1);
if (ulwk0){
	lwk1 = vhdclsp + (vdclas64 / 0x40) - vdclst64;
//	if (!(lwk1 <= 0xFFFFFFFF)){				//<024>端階強制減速対応 2018.04.25[K.Sakai]
	if (!(lwk1 <= (LONG)0xFFFFFFFF)){
		*vdclw = lwk1;
	}
	vdclat64 += (LONG)hdc1cmd;
	vdclas64 += vdclat64;
	vdclst64 += (LONG)(hdcccd64 / 0x40);
}
//
ulwk3 = ulwk0 & (!(*(vdclw + 1) > *vdclw) * -1);
if (ulwk3){
	vlstat |= BIT2;
	lwk1 = vdclspd - *vdclw;
//	if (!(lwk1 <= 0xFFFFFFFF)){				//<024>端階強制減速対応 2018.04.25[K.Sakai]
	if (!(lwk1 <= (LONG)0xFFFFFFFF)){
		vspcmd = lwk1;
	}
}
//
ulwk2 = ulwk0 & (!(*(vdclw + 1) > *vdclw) -1);
if (ulwk2 && !(vspcmd >= (vtopcmd + (LONG)hlmspcmd) / 2)){
	vdcccd64 = vdclat64;
	vlstat |= BIT2 | BIT3;
}
//
ulwk3 = ulwk2 & (!(vspcmd >= (vtopcmd + (LONG)hlmspcmd) / 2) -1);
if (ulwk3){
	*(vdclw + 1) = *vdclw;
	lwk1 = vdclspd - *vdclw;
	if (!(lwk1 >= vtopcmd)){
		vspcmd = lwk1;
	}
}
//*****@ed_vdclw[0],vdclat64,vdclas64,vdclst64,vlstat,vspcmd,vdcccd64,vdclw[1]
//*****@st_vspcmd,vlstat,vdcccd64
ulwk0 = (!(vlstat & BIT3) * -1) & (!(vlstat & BIT2) -1);
if (ulwk0){
	lwk1 = vdclspd - *(vdclw + 1);
//	if (!(lwk1 <= 0xFFFFFFFF)){				//<024>端階強制減速対応 2018.04.25[K.Sakai]
	if (!(lwk1 <= (LONG)0xFFFFFFFF)){
		vspcmd = lwk1;
	}
}
ulwk2 = 0;
if (ulwk0){
	if (vspcmd < (LONG)(hlmspcmd + hdc1sp)){
		vlstat |= BIT3;
		vdcccd64 = (LONG)hdcccd64;
		ulwk2 = (ULONG)-1;
	}
	else{
		vdcccd64 = (LONG)hdcccd64;
	}
}
//*****@ed_vspcmd,vlstat,vdcccd64
//*****@st_vdcccd64,vlstat,vtopcmd,vspcmd
ulwk1 = 0;
ulwk3 = 0;
//
ulwk0 = ~ulwk2 & (!(vlstat & BIT4) * -1) & (!(vlstat & BIT3) -1);
if (ulwk0){
//	if(!((LONG)(vdcccd64 - (LONG)hdc1cmd) <= 0xFFFFFFFF)){		//<024>端階強制減速対応 2018.04.25[K.Sakai]
	if(!((LONG)(vdcccd64 - (LONG)hdc1cmd) <= (LONG)0xFFFFFFFF)){
		if (vdcccd64 - (LONG)hdc1cmd > 0x20){
			vdcccd64 -= (LONG)hdc1cmd;
		}
	}
	lwk1 = vspcmd - (LONG)vdcccd64 / 0x40;
//	if (!(lwk1 <= 0xFFFFFFFF)){		//<024>端階強制減速対応 2018.04.25[K.Sakai]
	if (!(lwk1 <= (LONG)0xFFFFFFFF)){
		lwk3 = lwk1;
	}
}
if (ulwk0){
	if (lwk3 <= (LONG)hlmspcmd){
		vlstat |= BIT4;
		vtopcmd = (LONG)hlmspcmd;
		vspcmd = (LONG)hlmspcmd;
	}
	else{
		vspcmd = lwk3;
	}
}
//*****@ed_vdcccd64,vlstat,vtopcmd,vspcmd
//*****@st_vdclspd,vdclw[0],vlstat,vspmod,vhdclsp
set_imask(13);								//ﾃﾞｼﾞﾌﾛﾏｲﾅｽ停止不具合修正
//ulwk0 = ulwk2 & (((!(h10sys(0) & BIT5) -1) & v11) | ((!(h10sys(0) & BIT0) -1) & v12)) & v92;	//式修正(ulwk2をｶｯｺ外に出す)	//<024>端階強制減速対応 2018.04.25[K.Sakai]
ulwk0 = (((!(h10sys(0) & BIT5) -1) & v11) | ((!(h10sys(0) & BIT0) -1) & v12)) & v92;
ulwk0 = ulwk0 & (!(vstat & BIT8) * -1) & (!(vstat & BIT7) -1);
//ulwk0 = ulwk0 & (!((vspmxh * 15) > htermlm) -1);		//<024>端階強制減速対応 2018.04.25[K.Sakai]
ulwk0 = ulwk0 & (!(vspmxh > htermlm) -1);
lwk1 = 0;
if (hdc2ln & BIT15){
	lwk4 = (LONG)(0xFFFF0000 | hdc2ln);
}
else{
	lwk4 = (LONG)hdc2ln;
}
if (ulwk0){
	if (v11 & BIT31){
		if ((LONG)p900psh < (LONG)0x0){
			lwk1 = (*(ipm300pt + (ipm300 - 1)) & 0xFFFFF) - (lwk4/*(LONG)hdc2ln*/ / 0x4);
        }
        else{
			lwk1 = vabssign((LONG)(*(ipm300pt + (ipm300 - 1)) & 0xFFFFF) , (p900psh & 0xFFFFF)) - (lwk4/*(LONG)hdc2ln*/ / 0x4);
        }
	}
	if (v12 & BIT31){
		if ((LONG)p900psh < (LONG)0x0){
			lwk1 = (*(ipm300pt + 2) & 0xFFFFF) - (lwk4/*(LONG)hdc2ln*/ / 0x4);
		}
		else{
			lwk1 = vabssign((p900psh & 0xFFFFF) , (LONG)(*(ipm300pt + 2) & 0xFFFFF)) - (lwk4/*(LONG)hdc2ln*/ / 0x4);
		}		
	}
	if (lwk1 >= 0){    									//lwk0<0の時lwk0=0
		lwk1 = lwk1;
	}
	else{
		lwk1 = 0;
	}
	ulwk2 = (ULONG)lwk1 * hdcspd;
}
if (ulwk0){
//↓//<024>端階強制減速対応 2018.04.25[K.Sakai]
//	if(0xFFFFFFFF >= ulwk2){								//ulwk2のｵｰﾊﾞｰﾌﾛｰ対策
//		ulwk1 = ulwk2;									//ulwk2のｵｰﾊﾞｰﾌﾛｰ対策
//	}
//	else{
//		ulwk1 = 0xFFFFFFFF; 								//ulwk2のｵｰﾊﾞｰﾌﾛｰ対策
//	}
//	lwk1 = (LONG)r2roots(ulwk1);								//ulwk2のｵｰﾊﾞｰﾌﾛｰ対策
//	vdclspd = lwk1;
	if(ulwk2 < 0x3FFF0001){
		lwk1 = (LONG)r2roots(ulwk2);
		vdclspd = lwk1;
	}else{
		lwk1 = (LONG)r2roots(ulwk2/4);
		vdclspd = lwk1*2;
	}
//↑<024>
}
//
ulwk0 = ulwk0 & (!(vlstat & BIT1) * -1);
if (ulwk0){
	if (!(vdclspd - vspcmd >= (LONG)hdc1sp)){
		*(vdclw + 1) = 0xFFFF;
		vlstat |= BIT1;
		vspmod = 5;
		vhdclsp = vdclspd - vspcmd;
	}
	else{
		vhdclsp = vdclspd - vspcmd;
	}
}
set_imask(0);
//*****@ed_vdclspd,vdclw[0],vlstat,vspmod,vhdclsp
//*****@st_pcmpln,pcmpln1,vdccln,vdc2sp,vdcspd,vdccw[1],vstat,vspmod,vhdccsp,varvtm
ulwk1 = (!(vstat & BIT7) -1) & (~zv92k | zv15ka) & zv92;
if (ulwk1 && !(vstat & BIT8)){
	pcmpln = 0;
}
//
ulwk2 = ulwk1 & (!(vstat & BIT8) -1) & (!(vstat & BIT9) * -1) & (!(vspcmd <= vdcspd) -1);
if (ulwk2){
	pcmpln1 += (vdcspd - vspcmd) / 0x78;
	pcmpln = pcmpln1 / 6;
}
//
lwk2 = 0;
//
if (vwdccln & BIT15){
	lwk5 = (LONG)(0xFFFFFF00 | vwdccln);
}
else{
	lwk5 = (LONG)vwdccln;
}
//
if (ulwk1){
	if (v11 & BIT31){
		if((!(hvsys(3) & BIT7) *-1) || ih105fg){		//直引きﾏｲｸﾛ停止処理時無効
		if ((0xFF & (LONG)h105(1)) & BIT7){
			lwk0 = (LONG)(0xFFFFFF00 | (0xFF & (LONG)h105(1)));
		}
		else{
			lwk0 = (LONG)((0xFF & (LONG)h105(1)));	
		}
		}else{
			lwk0 = 0x00000003;
		}
		if((h10sys(6) & BIT6) && vdxfms3){				//TB3-0016 電子安全Lv4 階高測定 H.Sakamoto
			lwk2 = (LONG)*(ipm300pt + p300) + lwk0 - lwk5/*(LONG)vwdccln*/ - (p900psh + 0x01000000) - (hpps1 + 0x1A);	//TB3-0016 電子安全Lv4 階高測定 H.Sakamoto
		}else{
			lwk2 = (LONG)*(ipm300pt + p300) + lwk0 - lwk5/*(LONG)vwdccln*/ - (p900psh + 0x01000000);
		}
	}
	else{
		if((!(hvsys(3) & BIT7) *-1) || ih105fg){		//直引きﾏｲｸﾛ停止処理時無効
		if ((0xFF & (LONG)h105(2)) & BIT7){
			lwk0 = 0xFFFFFF00 | (0xFF & (LONG)h105(2));
		}
		else{
			lwk0 = (0xFF & (LONG)h105(2));	
		}
		}else{
			lwk0 = 0x00000003;
		}
		if((h10sys(6) & BIT6) && vdxfms3){				//TB3-0016 電子安全Lv4 階高測定 H.Sakamoto
			lwk2 = (p900psh + 0x01000000) + lwk0 - lwk5/*(LONG)vwdccln*/ - (LONG)*(ipm300pt + p300) - (hpps1 + 0x1A);	//TB3-0016 電子安全Lv4 階高測定 H.Sakamoto
		}else{
			lwk2 = (p900psh + 0x01000000) + lwk0 - lwk5/*(LONG)vwdccln*/ - (LONG)*(ipm300pt + p300);
		}
	}
}
//
if (ulwk1){
	if (!(lwk2 < 0)){
		if (lwk2 >= 0x10000){
			vdccln = 0xFFFF;
		}
		else{
			vdccln = lwk2;
		}
	}
	else{
		vdccln = 0;
	}
}
//
lwk2 = 0;
//
if (ulwk1){
	if (((LONG)hcmpln + vdccln) >= 0xFFFF){
		lwk2 = 0xFFFF;
	}
	else{
		lwk2 = (LONG)hcmpln + vdccln;
	}
}
//
if (ulwk1){
	vdc2sp = (((vtopcmd * (LONG)hdc2spw) / ((LONG)hdc1sp + (LONG)hdc2spw)) & 0xFFFF);
}
//
lwk3 = 0;
//
if (ulwk1){  
	if (vdc2sp <= (LONG)hdc2spw){
		lwk3 = ((((LONG)hdccln * vdc2sp) / (LONG)hdc2spw) & 0xFFFF);
	}
	else{
		lwk3 = (LONG)(hdccln & 0xFFFF);
	}
}
//
ulwk4 = ulwk1 & (!(lwk2 > lwk3) -1) & (!(lwk2-lwk3 > pcmpln) -1);	
lwk1 = 0;
if (ulwk4){
	lwk1 = lwk2 - lwk3 - pcmpln;
}
else{
	if (ulwk1){
		if (((lwk2 > lwk3) && !(lwk2 - lwk3 > pcmpln)) || !(lwk2 > lwk3)){
			lwk1 = 0;
		}
	}
}
//
ulwk3 = 0;
if (ulwk1){
	ulwk0 = lwk1 * hdcspd;
	if (ulwk0 >= 0xFFFFFFFF){
		ulwk3 = 0xFFFFFFFF;
	}
	else{
		ulwk3 = ulwk0;
	}
	lwk0 = (LONG)r2roots(ulwk3);
	vdcspd = lwk0 & 0xFFFF;
}
//
ulwk4 = ulwk1 & (!(vstat & BIT8) * -1);
if (ulwk4){
	if (vdcspd - vspcmd < (LONG)hdc1sp){
		*(vdccw + 1) = 0xFFFF;
		vstat |= BIT8;
		vspmod = 6;
		vhdccsp = vdcspd - vspcmd;
	}
	else{
		vhdccsp = vdcspd - vspcmd;
	}
}
//
lwk2 = 0;
if (ulwk1){
	lwk2 = ((vdcspd *102) / (LONG)hdcccd64) / 0x10;
	if (!(lwk2 > 0xFF)){
		varvtm = lwk2;
	}
	else{
		varvtm = 0xFF;
	}
}
//*****@st_pcmpln,pcmpln1,vdccln,vdc2sp,vdcspd,vdccw[1],vstat,vspmod,vhdccsp,varvtm
//*****@ed_v6d70l

//*****@st_v6d80l
//*****@st_vspcmd
if (vstat & BIT8){
	if (h15spcmd != 0){
		vspdcd = vspcmd / (LONG)h15spcmd;
	}
	else{
		vspdcd = 0;
	}
}
//*****@ed_vspcmd
//*****@st_vpdset
if (!za10h && !zv92){									//ﾏｲｸﾛ建築基準法改善
	vpdset = 0;
}
//*****@ed_vpdset
//*****@st_mpstat,mpstatz1,ctmpster1,ctmpster2,ctmpster3,txmpser			//<microﾎﾟｼﾞによる停止処理>
//<mpstat演算処理>
if((za10h || za10l) && ~za10c && (!(hvsys(2) & BIT1) -1)){	//<microﾎﾟｼﾞによる停止処理>
	mpstatz2 = mpstatz1;
	mpstatz1 = mpstat;

	if(!(xvfml & BIT31)){
		if(!(zxrs21 & BIT31)){
			if(!(zxrs22 & BIT31)){
				mpstat=1;			//xfml,xrs21,xrs22=000状態
				vxmpser = ~BIT28 & ~BIT27 & vxmpser;	//rs21&rs22ｵﾝ故障BITｸﾘｱ
			}
			else{
				mpstat=2;			//xfml,xrs21,xrs22=001状態
				vxmpser = ~BIT30 & vxmpser;	//rs22ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT27 & vxmpser;	//rs21ｵﾝ故障BITｸﾘｱ
			}
		}
		else{
			if(!(zxrs22 & BIT31)){
				mpstat=3;			//xfml,xrs21,xrs22=010状態
				vxmpser = ~BIT28 & vxmpser;	//rs22ｵﾝ故障BITｸﾘｱ
				vxmpser = ~BIT29 & vxmpser;	//rs21ｵﾌ故障BITｸﾘｱ
			}
			else{
				mpstat=4;			//xfml,xrs21,xrs22=011状態
				vxmpser = ~BIT30 & vxmpser;	//rs22ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT29 & vxmpser;	//rs21ｵﾌ故障BITｸﾘｱ
			}
		}
	}
	else{		//(xvfml & BIT31)=ｵﾝ
		if(!(zxrs21 & BIT31)){
			if(!(zxrs22 & BIT31)){
				mpstat=5;			//xfml,xrs21,xrs22=100状態
				vxmpser = ~BIT28 & ~BIT27 & vxmpser;	//rs21&rs22ｵﾝ故障BITｸﾘｱ
			}
			else{
				mpstat=6;			//xfml,xrs21,xrs22=101状態
				vxmpser = ~BIT30 & vxmpser;	//rs22ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT25 & vxmpser;	//rs21,rs22同時ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT27 & vxmpser;	//rs21ｵﾝ故障BITｸﾘｱ
			}
		}
		else{
			if(!(zxrs22 & BIT31)){
				mpstat=7;			//xfml,xrs21,xrs22=110状態
				vxmpser = ~BIT29 & vxmpser;	//rs21ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT25 & vxmpser;	//rs21,rs22同時ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT28 & vxmpser;	//rs22ｵﾝ故障BITｸﾘｱ
			}
			else{
				mpstat=8;			//xfml,xrs21,xrs22=111状態
				vxmpser = ~BIT30 & ~BIT29 & vxmpser;	//rs21,rs22ｵﾌ故障BITｸﾘｱ
				vxmpser = ~BIT25 & vxmpser;	//rs21,rs22同時ｵﾌ故障BITｸﾘｱ
			}
		}
	}
	if(!(vxmpser & 0x7FFFFFFF)){
		vxmpser = 0;		//on,off故障復帰
	}
//<故障判定処理①－１>；mpstat異常状態を2s以上継続で異常検出(ｵﾝ故障)
//<故障判定処理①－１>；rs21,rs22ｵﾝ状態を10m/min,2s以上継続で異常検出(ｵﾝ故障)
	if(vxsped >= 10){
		if((mpstat == 1) || (mpstat == 5)){
			ulwk0 = 0;
		}
		if ((mpstat == 2) || (mpstat == 3) || (mpstat == 4) || (mpstat == 6) || (mpstat == 7) || (mpstat == 8)){
			ulwk0 = (ULONG)-1;
		}
	}
	else{
		ulwk0 = 0;
	}
	*tmpster1 = ctmpster1.cmt(ulwk0);
//<故障判定処理①－１－２>；端階ｿﾞｰﾝでrs21,rs22ｵﾝ状態を3m/min,6s以上継続で異常検出(ｵﾝ故障)
	if((xsds1d || xsds1u) && (vxsped >= 3)){
		if((mpstat == 1) || (mpstat == 5)){
			ulwk0 = 0;
		}
		if ((mpstat == 2) || (mpstat == 3) || (mpstat == 4) || (mpstat == 6) || (mpstat == 7) || (mpstat == 8)){
			ulwk0 = (ULONG)-1;
		}
	}
	else{
		ulwk0 = 0;
	}
	*tmpster3 = ctmpster3.cmt(ulwk0);
//<故障判定処理①－２>	mpsat=5(xfml=on xrs21=off xrs22=off)2s以上継続で異常検出(ｵﾌ故障)
//			速度条件(vxsped >= 1)追加；ﾀｲﾏｰ値2→1sに変更
//				 ↑速度指令のほうがいいかも↑RSきってから止まるまで通常は約1s程度
	if(vspdfb){
		if(mpstat == 5){
			ulwk0 = (ULONG)-1;
		}else{
			ulwk0 = 0;
		}
	}
	else{
		ulwk0 = 0;
	}
	*tmpster2 = ctmpster2.cmt(ulwk0);
//<故障判定処理②>；mpstat異常状態遷移でﾏｲｸﾛﾎﾟｼﾞｵﾌ故障検出
	if((x15b) && (vxsped < 0x19)){	//停止時復帰対策  //走行中にrs21,rs22検出不能時TCD=AA不要検出対策
		if((v11 || v16up) && vx11pl && (mpstat == 5) && (vxsped > 0)){
			if((mpstatz1 == 7) && (mpstatz2 == 7)){
				vxmpser |= BIT31;
				vxmpser |= BIT30;		//rs22off故障
			}
		}
		if((v11 || v16up) && vx11pl && (mpstat == 6) && (vxsped > 0)){
			if((mpstatz1 == 5) && (mpstatz2 == 5)){
				vxmpser |= BIT31;
				vxmpser |= BIT29;		//rs21off故障
			}
		}
		if((v12 || v16dn) && vx12pl && (mpstat == 5) && (vxsped > 0)){
			if((mpstatz1 == 6) && (mpstatz2 == 6)){
				vxmpser |= BIT31;
				vxmpser |= BIT29;		//rs21off故障
			}
		}
		if((v12 || v16dn) && vx12pl && (mpstat == 7) && (vxsped > 0)){
			if((mpstatz1 == 5) && (mpstatz2 == 5)){
				vxmpser |= BIT31;
				vxmpser |= BIT30;		//rs22off故障
			}
		}
	}
	if((ctmpster1.dmt()) || (ctmpster3.dmt())){			//走行中のrs21,rs22 on故障 //端階ｿﾞｰﾝ低速条件追加
		vxmpser |= BIT31;
		if((mpstat ==2) || (mpstat ==6)){	//fmlon故障条件追加
			vxmpser |= BIT28;		//rs22のon故障
		}
		if((mpstat ==3) || (mpstat ==7)){	//fmlon故障条件追加
			vxmpser |= BIT27;		//rs21のon故障
		}
		if((mpstat ==4) || (mpstat ==8)){	//fmlon故障条件追加
			vxmpser |= BIT28;		//rs22のon故障
			vxmpser |= BIT27;		//rs21のon故障
		}
	}
	if(ctmpster2.dmt()){			//停止中のrs21,rs22同時off故障検出
			vxmpser |= BIT31;
			vxmpser |= BIT25;		//rs21,rs22同時off故障
	}
}
//*****@ed_mpstat,mpstatz1,ctmpster1,ctmpster2,ctmpster3,txmpser			//<microﾎﾟｼﾞによる停止処理>
//*****@st_wpbh[2],v10h,vspmod,p900pd,wvbh[5],tp900pd,vstat
ulwk0 = za10h & zv92 & (~zv49h | (zv49h & (!(pstat & BIT3) -1)));
ulwk1 = ulwk0 & ((v11 & (!((LONG)*(ipm300pt + p300) + (LONG)iovrln < (p900psh + 0x01000000)) -1)) | 
	(v12 & (!((LONG)*(ipm300pt + p300) - (LONG)iovrln > (p900psh + 0x01000000)) -1)));
if (ulwk1){
	if (v10h && !(*(wpbh + 2) & BIT15)){
		*(wpbh + 2) += 1;
	}
	v10h = 0;
	vspmod = 0;
	vhlverr[0] |= BIT10;						//herios予兆(ﾃﾞｼﾞﾌﾛｵｰﾊﾞｰﾗﾝ)
	vhlverr[1] = p900;
}
//
ulwk1 = ulwk0 & (!((xvdza | xvdzb) >= 0xFFFF0000) -1) & v102fh;
if (*(vrunt + 2) - *(vrunt + 3) < 0x3A98){
	ulwk0 = ulwk1 & ~zvasalp & (!((*(vrunt + 2) - *(vrunt + 3)) > 12000) -1);
}
else {
	ulwk0 = 0;
}						
//
ulwk2 = ulwk1 & ((~zvasalp & (!((*(vrunt + 2) - *(vrunt + 3)) > 12000) * -1)) | zvasalp);
//
if (ulwk0){
	vstat |= BIT14;
	vspmod = 0xA;
	vstopck |= BIT0;	//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
}
//C03 追加 2014.05.20[D.Chen]↓tsaelver
	if(ulwk2 && hsae1 && (hlvgain != 0)){
//		if(!(h10sys(7) & BIT7)){	//電子安全時pbtmflh=0ｾｯﾄにより統一 2014.07.22[D.Chen]
			lwk0 = vabssign((LONG)plevel1,pbtmflh);
//		}else{
//			lwk0 = vabssign((LONG)plevel1,0);
//		}
		lwk0 = vabssign(lwk0,0);
		udwk0 = (double)lwk0 * (double)hmmunt / 0x1000000;
		tsaelver = (!(((LONG)(ipm300pt[p900] & 0xFFFFF) - 50) >= (LONG)udwk0)-1) | (!(((LONG)(ipm300pt[p900] & 0xFFFFF) + 50) <= (LONG)udwk0)-1) |
//			(!(tsae1e & BIT31)-1) | (!(tp900c & BIT31)-1) | tvmcr | ~vflsae | ~psaelvok | ((tsafeer & BIT31) & (!(h10sys(7) & BIT7)-1));    //変更 2014.08.19[D.Chen]
			(!(tsae1e & BIT31)-1) | (!(tp900c & BIT31)-1) | tvmcr | ~vflsae | ~psaelvok | ((tesaecom |(!(everstat & 0x70)-1)) & (!(h10sys(7) & BIT7)-1));
	}
//C03 追加 2014.05.20[D.Chen]↑
//
ulwk3 = ulwk2 & v11 & ~p900pdck;
//
if (ilvl & BIT15){
	lwk5 = (LONG)(0xFFFF0000 | ilvl);
}
else{
	lwk5 = (LONG)ilvl;
}
//
if (ulwk3){
	if(!(h10sys(6) & BIT6)){ //TB3-0025 基準位置センサ非適用時 H.Sakamoto
		p900pd = (*(ipm300pt + p900) & 0xFFFFF) - lwk5/*(LONG)ilvl*/; 
	}else{					 //TB3-0025 基準位置センサ適用時   H.Sakamoto
		p900pd = (*(ipm300pt + p900) & 0xFFFFF) - ((*(iv105ntbl + p900) / 0x100) & 0xFF) - lwk5/*(LONG)ilvl*/;
	}
	if (!vpdset){									//ﾏｲｸﾛ建築基準法改善
		p900psm = (*(ipm300pt + p900) & 0xFFFFF) - lwk5/*(LONG)ilvl*/;		//ﾏｲｸﾛ建築基準法対応
		vpdset = (ULONG)-1; 
	}
	if (!tp900pd){
		if(!(*(wvbh + 5) & BIT31)){
			*(wvbh + 5) += 1;
		}
		tp900pd = (ULONG)-1;
//
		vhlverr[0] |= BIT9;							//herios予兆(遮蔽板検出失敗)
		vhlverr[1] = p900;
	}
}
//
ulwk5 = 0;
if ((ulwk2 && v11 && !p900pdck && tp900pd) || (ulwk2 && v11 && p900pdck)){		//短階床の停止位置補正回路追加
        if (p900st == ((i49efl1 / 0x10000000) & 0xF)){
                if (p900 == ((i49efl2 / 0x10000000) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x1000000) & 0xF)){
                if (p900 == ((i49efl2 / 0x1000000) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x100000) & 0xF)){
                if (p900 == ((i49efl2 / 0x100000) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x10000) & 0xF)){
                if (p900 == ((i49efl2 / 0x10000) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x1000) & 0xF)){
                if (p900 == ((i49efl2 / 0x1000) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x100) & 0xF)){
                if (p900 == ((i49efl2 / 0x100) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x10) & 0xF)){
                if (p900 == ((i49efl2 / 0x10) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else if (p900st == ((i49efl1 / 0x1) & 0xF)){
                if (p900 == ((i49efl2 / 0x1) & 0xF)){
                        ulwk5 = h105up1;
                }
                else{
                		ulwk5 = h105(1);
                }
        }
        else {
            ulwk5 = h105(1);
	}
}
ulwk1 = ulwk2 & ~v11 & v12 & ~p900pdck;
ulwk4 = (ulwk2 & ~v11 & v12 & p900pdck) | (ulwk2 & ~v11 & ~v12);
if (ulwk1){
	if(!(h10sys(6) & BIT6)){ //TB3-0025 基準位置センサ非適用時 H.Sakamoto
		p900pd = (*(ipm300pt + p900) & 0xFFFFF) + lwk5/*(LONG)ilvl*/;   
	}else{					 //TB3-0025 基準位置センサ適用時   H.Sakamoto
		p900pd = (*(ipm300pt + p900) & 0xFFFFF) + ((*(iv105ntbl + p900) / 0x100) & 0xFF) + lwk5/*(LONG)ilvl*/;
	}
	if (!vpdset){											//ﾏｲｸﾛ建築基準法改善
		p900psm = (*(ipm300pt + p900) & 0xFFFFF) + lwk5/*(LONG)ilvl*/;				//ﾏｲｸﾛ建築基準法対応
		vpdset = (ULONG)-1; 
	}
	if (!tp900pd){
		if(!(*(wvbh + 5) & BIT31)){
			*(wvbh + 5) += 1;
		}
		tp900pd = (ULONG)-1;
//
		vhlverr[0] |= BIT9;									//herios予兆(遮蔽板検出失敗)
		vhlverr[1] = p900;
	}
}
//
if ((ulwk1 && tp900pd) || ulwk4){									//短階床の停止位置補正回路追加
        if (p900st == ((i49efl2 / 0x10000000) & 0xF)){
                if (p900 == ((i49efl1 / 0x10000000) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x1000000) & 0xF)){
                if (p900 == ((i49efl1 / 0x1000000) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x100000) & 0xF)){
                if (p900 == ((i49efl1 / 0x100000) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x10000) & 0xF)){
                if (p900 == ((i49efl1 / 0x10000) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x1000) & 0xF)){
                if (p900 == ((i49efl1 / 0x1000) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x100) & 0xF)){
                if (p900 == ((i49efl1 / 0x100) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x10) & 0xF)){
                if (p900 == ((i49efl1 / 0x10) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else if (p900st == ((i49efl2 / 0x1) & 0xF)){
                if (p900 == ((i49efl1 / 0x1) & 0xF)){
                        ulwk5 = h105dn1;
                }
                else{
                		ulwk5 = h105(2);
                }
        }
        else {
            ulwk5 = h105(2);
	}
}
//
if(ulwk2){
//	if((!(tp900r & BIT31) * -1) && (!(tp900re & BIT31) * -1)){			//階高未完時は補正無効
	if(((!(tp900r & BIT31) * -1) && (!(tp900re & BIT31) * -1)) && ((LONG)(*(ipm300pt + ipm300) & 0xFFFFF) != 0)){			//分母0対応 2014.07.23 [N.Takayama]
		if((LONG)p900psh < (LONG)0x0){
			lwk6 = (LONG)((LONG)((hstpadj / 0x100) & 0xFF) * (LONG)(*(ipm300pt + ipm300) & 0xFFFFF) / (LONG)(*(ipm300pt + ipm300) & 0xFFFFF) * (LONG)v65rg / (LONG)0x64);
			lwk7 = (LONG)((LONG)(hstpadj & 0xFF) * (LONG)(*(ipm300pt + ipm300) & 0xFFFFF) / (LONG)(*(ipm300pt + ipm300) & 0xFFFFF) * (LONG)v65rg / (LONG)0x64);
		}else {
			lwk6 = (LONG)((LONG)((hstpadj / 0x100) & 0xFF) * vabssign((LONG)(*(ipm300pt + ipm300) & 0xFFFFF),(p900psh & 0xFFFFF)) / (LONG)(*(ipm300pt + ipm300) & 0xFFFFF) * (LONG)v65rg / (LONG)0x64);
    		lwk7 = (LONG)((LONG)(hstpadj & 0xFF) * vabssign((LONG)(*(ipm300pt + ipm300) & 0xFFFFF),(p900psh & 0xFFFFF)) / (LONG)(*(ipm300pt + ipm300) & 0xFFFFF) * (LONG)v65rg / (LONG)0x64);
		}
	}else {   													//階高未完時は補正無効
		lwk6 = 0;
		lwk7 = 0;
	}
//
//	if(tsaelver || !hsae1 || ((hlvgain & 0xFFFF) == 0)){	//C03 追加 2014.05.20[D.Chen] SAE付き時はｽｷｯﾌﾟ(SAE優先) //復活 2014.08.16[T.Matsukuma]
//	if(tsaelver || !hsae1 || ((hlvgain & 0xFFFF) == 0) || !isaeland){	//SAE着床ｽﾍﾟｯｸ追加2014.07.22[D.Chen]
	if((tsaelver || !hsae1 || ((hlvgain & 0xFFFF) == 0)) && !(h10sys(6) & BIT6)){ //TB3-0025 基準位置センサ適用時ｽｷｯﾌﾟ
	if((!(hvsys(2) & BIT1) -1) && (!(h10sys(1) & BIT3) -1)){	//RMﾏｲｸﾛﾎﾟｼﾞｽﾍﾟｯｸ追加
		if(!(vxmpser & BIT31) * -1){		//<microﾎﾟｼﾞによる停止処理>
		if(!(hvsys(3) & BIT7)* -1){	//直引きﾏｲｸﾛﾎﾟｼﾞ停止処理
			if(p900pdmx && ((!(zxrs22 & BIT31) -1) && (!(zxrs21 & BIT31) -1))){	//<micro停止>条件追加
				if (( v11 &&        ((LONG)(p900pdm + (LONG)h105upm + lwk6) <= (LONG)p900psh))
				||  (!v11 && v12 && ((LONG)(p900pdm - (LONG)h105dnm + lwk7) >= (LONG)p900psh))){	//<micro停止>条件変更
					vstat |= BIT14;
					vspmod = 0xA;
					pderflg3 = (ULONG)-1;
					vstopck |= BIT1;		//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
				}											//<micro停止>
			}
		}else{
			if(p900pdmsx && ((!(vxrs22s & BIT31) -1) && (!(vxrs21s & BIT31) -1))){	//<直引きmicro停止>条件追加
				if (( v11 &&        ((LONG)(p900pdms + (LONG)h105upm + lwk6) <= (LONG)p900psh))
				||  (!v11 && v12 && ((LONG)(p900pdms - (LONG)h105dnm + lwk7) >= (LONG)p900psh))){
					vstat |= BIT14;
					vspmod = 0xA;
					pderflg3 = (ULONG)-1;
					vstopck |= BIT4;		//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
				}											//<micro停止>
			}
		}
			}
		if((p900 == p300) && !p900pdmx){		//<microﾎﾟｼﾞoff故障による停止処理>//ﾏｲｸﾛｿﾞｰﾝ内停止間際でﾏｲｸﾛﾎﾟｼﾞoff故障検出で停止処理
			if (txmpser2){
				*(wrbh + 11) += 1;	//mode2記録追加
			}
		}
		if(!(vxmpser & BIT31) -1){
			if (( v11 &&        ((LONG)(p900pd + (LONG)(ulwk5 / 0x100) + lwk6) <  (LONG)p900psh))
			  ||(!v11 && v12 && ((LONG)(p900pd - (LONG)(ulwk5 / 0x100) + lwk7) >= (LONG)p900psh))){
				vstat |= BIT14;
				vspmod = 0xA;
				pderflg1 = (ULONG)-1;
				vstopck |= BIT2;			//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
			}
			if ((!pderflg1 &&  v11 &&        ((LONG)(p900pda + (LONG)(ulwk5 / 0x100) + lwk6) <  (LONG)p900psh))
			  ||(!pderflg1 && !v11 && v12 && ((LONG)(p900pda - (LONG)(ulwk5 / 0x100) + lwk7) >= (LONG)p900psh))){
				vstat |= BIT14;
				vspmod = 0xA;
				pderflg2 = (ULONG)-1;
				vstopck |= BIT3;			//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
//
				vhlverr[0] |= BIT8;													//<16>herios予兆(p900pd異常ﾊﾞｯｸｱｯﾌﾟ) 07.03.06 M
				vhlverr[1] = p900;
			}
		}
	}else{
		if (( v11 &&        ((LONG)(p900pd + (LONG)(ulwk5 / 0x100) + lwk6) <  (LONG)p900psh))
		  ||(!v11 && v12 && ((LONG)(p900pd - (LONG)(ulwk5 / 0x100) + lwk7) >= (LONG)p900psh))){
			vstat |= BIT14;
			vspmod = 0xA; 
			pderflg1 = (ULONG)-1;
			vstopck |= BIT4;				//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
		} 
		if ((!pderflg1 &&  v11 &&        ((LONG)(p900pda + (LONG)(ulwk5 / 0x100) + lwk6) <  (LONG)p900psh))
		  ||(!pderflg1 && !v11 && v12 && ((LONG)(p900pda - (LONG)(ulwk5 / 0x100) + lwk7) >= (LONG)p900psh))){
			vstat |= BIT14;
			vspmod = 0xA;
			pderflg2 = (ULONG)-1;
			vstopck |= BIT5;				//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
//
			vhlverr[0] |= BIT8;					//herios予兆(p900pd異常ﾊﾞｯｸｱｯﾌﾟ)
			vhlverr[1] = p900;
		}
	}
	}								//C03 追加 2014.05.20[D.Chen] SAE付き時はｽｷｯﾌﾟ(SAE優先)
//	
}
//*****@ed_wpbh[2],v10h,vspmod,p900pd,wvbh[5],tp900pd,vstat
//C03 追加 2014.05.20[D.Chen] SAE停止処理 ↓
if(ulwk2){
	if(!(h10sys(6) & BIT6)){ //TB3-0025 基準位置センサ非適用 H.Sakamoto
		ulwk0 = p900pdck & ~tsaelver & hsae1 & (!(hlvgain & 0x0000FFFF) -1);	//SAE着床ｽﾍﾟｯｸ追加2014.07.22[D.Chen]  //復活 2014.08.16[T.Matsukuma]
	//	ulwk0 = p900pdck & ~tsaelver & hsae1 & (!(hlvgain & 0x0000FFFF) -1) & isaeland;
		if(ulwk0){
			if(v11 && (0 < (LONG)(xsae1 - plevel1))){
				vstat |= BIT14;
				vspmod = 0xA;
				vstopck |= BIT6;					//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
			}else{
				if(v12 && (0 > (LONG)(xsae1 - plevel1))){
					vstat |= BIT14;
					vspmod = 0xA;
					vstopck |= BIT6;				//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
				}
			}
		}
		if(!p900pdck){							//<00*><10.03.06>Iw p900pdck補償回路追加
			if(( v11 && ((LONG)(p900pd + (LONG)(ulwk5 / 0x100) + lwk6) <  (LONG)p900psh))
		           ||(!v11 && v12 && ((LONG)(p900pd - (LONG)(ulwk5 / 0x100) + lwk7) >= (LONG)p900psh))){
		           vstat |= BIT14;
		           vspmod = 0xA;
		           vstopck |= BIT7;						//C03 追加 2014.05.20[D.Chen] 着床方法ﾁｪｯｸ(debug用)
			}
		}
	}
	//C03 追加 2014.05.20[D.Chen] SAE停止処理 ↑

	/*↓TB3-0025 基準位置センサ適用 H.Sakamoto*/
	if(h10sys(6) & BIT6){
		ulwk0 = p900pdck & ~tsaelver & hsae1 & (!(hlvgain & 0x0000FFFF) -1);
		if(ulwk0){
			/*第一優先 光学式センサの位置データによる着床*/
			if(v11 && (0 < (LONG)(xsae1 - plevel1))){
				vstat |= BIT14;
				vspmod = 0xA;
				vstopck |= BIT9;
			}else{
				if(v12 && (0 > (LONG)(xsae1 - plevel1))){
					vstat |= BIT14;
					vspmod = 0xA;
					vstopck |= BIT9;
		        }
			}
		}
		lwk8 = (LONG)((BYTE)((ulwk5 / 0x100) & 0xFF));	//符号付に変換
		if(!ulwk0){
			/*第二優先 第一優先着床不可時のデジフロ着床*/
			if (( v11 &&        ((LONG)(p900pd + ((*(iv105ntbl + p900) / 0x100) & 0xFF) + lwk8 + lwk6) <  (LONG)p900psh))
		      ||(!v11 && v12 && ((LONG)(p900pd - (*(iv105ntbl + p900) & 0xFF)           - lwk8 + lwk7) >= (LONG)p900psh))){
				vstat |= BIT14;
				vspmod = 0xA;
				pderflg1 = (ULONG)-1;
				vstopck |= BIT10;
			}
		}
	}
	/*↑TB3-0025 基準位置センサ適用 H.Sakamoto*/
}
//*****@st_vwdcct,vwdcclm
lwk3 = 0;
ulwk4 = 0;
ulwk0 = (!(vstat & BIT8) -1) & (!(vdccln > (LONG)iwdccln(0)) * -1);
if (ulwk0 && !(vwdcct > iwdccln(1))){
	vwdcct += 1;
	ulwk4 = (ULONG)-1;	//YES;
}
//
ulwk1 = ulwk4 & (!(hvsys(0) & BIT3) -1) & v10;
ulwk2 = ulwk4 & (!(hvsys(0) & BIT3) * -1) & (!(hvsys(0) & BIT2) -1) & v10;
if (ulwk1 && (vwctrq1 > 0x1000)){
	lwk3 = (iwdccln(2) * vwctrq1) / 0x4000;
}
if (ulwk2 && (vwctrq1 <= 0xF000)){
	lwk3 = (iwdccln(2) * vabs(vwctrq1,0)) / 0x4000;
}
//
vwdccln = (lwk3 * vwdcct) / 0x40; 
//*****@ed_vwdcct,vwdcclm
//*****@st_vspmod
if (v10 && (tsdsver1 & BIT31)){
	vspmod = 0xD;
}
//*****@ed_vspmod
//
if ((hhyb & BIT31) && vh97bp && v10 && !zv92 && (vspcmd > (vspcmdlm + 0x10)) && !vbvstat7){			//HYB ｽﾄｯﾌﾟﾚｽ減速開始
	if (vspcmdlm >= h15spcmd){
		vspcmdhy = vspcmdlm;
	}
	else{
		vspcmdhy = h15spcmd;
	}
	vstat |= BIT7;		
	vspmod = 0xE;
}
if ((hhyb & BIT31) && vh97bp && v10 && zv92 && (vspcmd > vspcmdmx)){						//HYB ｽﾄｯﾌﾟﾚｽ減速開始
	vspcmdhy = h15spcmd;
	vstat |= BIT7;
	vspmod = 0xD;
}
//*****@ed_vspmod
ulwk0 = (!(vstat & BIT7) -1);
*vstat7tm1 = cvstat7tm1.cmt(rmsb_yesnos(ulwk0));
cvstat7tm1.dmt();
if (vh97bp && cvstat7tm1.dmt()){
	vbvstat7 = 0;
}
if (!vi60supq && !v15b){
	vbatmod = 0;
}

//*****@st_herios								//herios予兆(着床ﾚﾍﾞﾙ異常)
if (cv97at.dmt()){
	if (vtrqcmd & BIT15){
		lwk1 = (LONG)(vtrqcmd | 0xFFFF0000);
	}
	else{
		lwk1 = (LONG)vtrqcmd;
	}
//												//減速時ﾄﾙｸﾘﾐｯﾀ動作	
	ulwk0 = (!(vstat & BIT8) -1) & (!(vabssign(lwk1,0) >= htrqlm1) -1);
	*hetrqlmt = chetrqlmt.cmt(ulwk0);
	chetrqlmt.dmt();
	if (chetrqlmt.dmt()){
		vhlverr[0] |= BIT3;
		vhlverr[1] = p900;
	}
}
//												//herios予兆(起動ｼｮｯｸ)
if (!v15b && !x15b){
	vspdrf1 = 0;								//ﾍﾘｵｽ予兆追加
	vspdfb1 = 0;
	vspdfb11 = 0;
	vhestshk[0] &= 0x00000008;
	if (!(vhestshk[0] & BIT3)){
		vhestshk[1] = 0;
	}
}
//												//ﾌﾞﾚｰｷ動作遅れ
if (cv97at.dmt()){
//↓<024>3連ブレーキ対応 2018.06.01[S.Kubo]
//		ulwk0 = v10h & (!(vstat & BIT2) *-1) & v60asr & ((!(xvenbcs1 & BIT31) *-1) | (!(xvenbcs2 & BIT31) *-1));
		ulwk0 = v10h & (!(vstat & BIT2) *-1) & v60asr & ((!(xvenbcs1 & BIT31) *-1) | (!(xvenbcs2 & BIT31) *-1) | ((!(h10sys(6) & BIT1) -1) & (!(xvenbcs3 & BIT31) *-1)));
//↑<024>
	if (ulwk0){
		vhestshk[0] |= BIT0;
		vhestshk[1] = p900;
	}
//
	if (vspdfb & BIT15){
		lwk1 = (LONG)(vspdfb | 0xFFFF0000);
	}
	else{
		lwk1 = (LONG)vspdfb;
	}
//
	if (vspdrf & BIT15){
		lwk2 = (LONG)(vspdrf | 0xFFFF0000);
	}
	else{
		lwk2 = (LONG)vspdrf;
	}
//												//引掛り検出(UP)
	if (v11){
		ulwk1 = (!(vstat & BIT7) *-1) & (!(vabssign(lwk2,0) > hstshc3) -1) & (!(vspdfb == 0) -1);
		if (ulwk1){
			vhestshk[0] |= BIT1;
			vhestshk[1] = p900;
//
			if (lwk2/*vspdrf*/ > vspdrf1){		//ﾍﾘｵｽ予兆追加
				vspdrf1 = lwk2;
			}		
		}			
	}
//												//引掛り検出(DN)
	if (v12){
		ulwk1 = (!(vstat & BIT7) *-1) & (!(vabssign(lwk2,0) > hstshc3) -1) & (!(vspdfb == 0) -1);
		if (ulwk1){
			vhestshk[0] |= BIT2;
			vhestshk[1] = p900;
//
			if (lwk2/*vspdrf*/ < vspdrf1){		//ﾍﾘｵｽ予兆追加
				vspdrf1 = lwk2;
			}		
		}			
	}
//												//飛出し検出(UP)
//↓<024>3連ブレーキ対応 2018.06.01[S.Kubo]
//		ulwk0 = ((!(xvenbcs1 & BIT31) -1) | (!(xvenbcs2 & BIT31) -1)) & (!(vspdrf == 0) -1) & v10h;	
		ulwk0 = ((!(xvenbcs1 & BIT31) -1) | (!(xvenbcs2 & BIT31) -1) | ((!(h10sys(6) & BIT1) -1) & (!(xvenbcs3 & BIT31) -1))) & (!(vspdrf == 0) -1) & v10h;
//↑<024>
	if (ulwk0){
		if (lwk1/*vspdfb*/ > vspdfb1){
			vspdfb1 = lwk1;
		}		
		if (lwk1/*vspdfb*/ < vspdfb11){
			vspdfb11 = lwk1;
		}
	}
//												//飛出し検出(UP)
	if (ulwk0 && v11 && !(vspdfb & BIT15) && (vabssign(vspdfb1,0) > hstshc1)){
		vhestshk[0] |= BIT4;
		vhestshk[1] = p900;
	}
//												//反転検出(UP)
	if (ulwk0 && v11 && (vspdfb & BIT15) && (vabssign(vspdfb11,0) > hstshc2)){
		vhestshk[0] |= BIT5;
		vhestshk[1] = p900;
	}
//												//反転検出(DN)
	if (ulwk0 && v12 && !(vspdfb & BIT15) && (vabssign(vspdfb1,0) > hstshc2)){
		vhestshk[0] |= BIT6;
		vhestshk[1] = p900;
	}
//												//飛出し検出(DN)
	if (ulwk0 && v12 && (vspdfb & BIT15) && (vabssign(vspdfb11,0) > hstshc1)){
		vhestshk[0] |= BIT7;
		vhestshk[1] = p900;
	}
}
//*****@ed_herios
//*****@ed_v6d80l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6dc0l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>: 						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6dc0l)                                               */
/************************************************************************/
//extern "C" ULONG rv6dc0ls(void);
ULONG rv6dc0ls(void){
//ユーザー用ワーク
register LONG lwk2;
ULONG ulwk0,ulwk1,ulwk3;

//*****@st_v6dc0l
//*****@st_vspcmd,vspmod,v10h,vabrans
lwk2 = 0;
ulwk0 = zv92k & (((!(h10sys(0) & (BIT5 | BIT6)) -1) & ~v15ka & ~cv92kt.dmt()) | ((!(h10sys(0) & (BIT5 | BIT6)) * -1) & ~zv15ka));
ulwk1 = zv92k & (((!(h10sys(0) & (BIT5 | BIT6)) -1) & ~v15ka & cv92kt.dmt()) | ((!(h10sys(0) & (BIT5 | BIT6)) -1) & v15ka) | ((!(h10sys(0) & (BIT5 | BIT6)) * -1) & zv15ka));
//
if (ulwk0){
	if (h10sys(2) & (BIT5 | BIT6)){
		lwk2 = (LONG)hrscddc;
	}
	else{
		lwk2 = (LONG)hrsccmd & 0xFF;
	}
}
ulwk3 = ulwk0 & (!(vspcmd >= lwk2) -1) & (!(vspcmd - lwk2 > (LONG)h15spcmd) -1);
if (ulwk3){
	vspcmd = vspcmd - lwk2;
}
lwk2 = 0;
if (ulwk1){
	lwk2 = vspcmd - (vspcmd / (LONG)hdcstop);
	if (!(lwk2 > (LONG)hdcstop)){
		vspcmd = 0;
		v10h = 0;
		vspmod = 0;
		vabrans = (ULONG)-1;
	}
	else{
		vspcmd = lwk2;
	}
}
//*****@ed_vspcmd,vspmod,v10h,vabrans
//*****@ed_v6dc0l
return (ULONG)-1;
}

/****************************************************************************
* NAME              =b14v6dd0l.cpp										 	*
* FUNCTION          =従ソフト部											 	*
* NOTE              =													 	*
* AUTHOR            =M.Furuhashi										 	*
* DATE              =2002.05.28											 	*
* ORIGINAL          =(FD No.)											 	*
* HISTORY           =<000>:変更内容 年(西暦2桁).月(2桁).日(2桁) [作成者名] 	*
*		     <003> 							*
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   	*
*****************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6dd0l)                                               */
/************************************************************************/
ULONG rv6dd0ls(void){
//ユーザー用ワーク
register ULONG ulwk0;
ULONG ulwk1,ulwk2;
LONG lwk0;

//*****@st_v6dd0l
*vhybsdtm = cvhybsdtm.cmt((ULONG)-1);						//HYB ｽﾄｯﾌﾟﾚｽ制御
vbatmod = ~cvhybsdtm.dmt() & vh97bp & (!(hhyb & BIT31)-1);			//HYB ｽﾄｯﾌﾟﾚｽ制御 
//*****@st_vsddcctm
*vsddcctm = cvsddcctm.cmt((ULONG)-1);
//*****@ed_vsddcctm
//*****@st_vsddcctx//<021>電気SDS
if (vspdfb & BIT15){
    lwk0 = (LONG)(0xFFFF0000 | vspdfb);
}
else{
    lwk0 = (LONG)vspdfb;
}
if (cvsddcctm.tmt()){
//  if (!(h10sys(3) & BIT7) || !(hvsys(3) & BIT3)){
  if (!(hvsys(3) & BIT3)){
    if (vabssign(lwk0,0) < hsdspcmd*hspgain/0x100 ){
        ulwk0 = (ULONG)-1;
    }
    else{
        ulwk0 = 0;
    }
  }else{
    if (vxsped < (ivaspdcd * 15 -15)){
        ulwk0 = (ULONG)-1;
    }
    else{
        ulwk0 = 0;
    }
  }
}
else{
    ulwk0 = 0;
}
vsddcctx = ulwk0;
//*****@ed_vsddcctx

//*****@st_tsds1acc
tsds1acc = (!(vstat & BIT7) * -1) & v10h;
//*****@ed_tsds1acc
//*****@st_vsdsdcc
    if (!vsddcctx){
        vsdsdcc = (LONG)hsdsdcc1;
    }
    else if (!tsds1acc){
        vsdsdcc = (LONG)hsdsdcc2;
    }
    else{
        vsdsdcc = (LONG)hsdsdcc3;
    }
//*****@ed_vsdsdcc
//*****@st_vspcmd
if (!(hvsys(3) & BIT3)){
    if (vspcmd - vsdsdcc >= (LONG)h15spcmd){
        vspcmd = vspcmd - vsdsdcc;
    }
}
else{
    if (vspcmd - vsdsdcc >= (LONG)h02spcmd){
        vspcmd = vspcmd - vsdsdcc;
    }
}
//*****@ed_vspcmd
//*****@st_psdsstp
//if ((vspcmd <= (LONG)h30spcmd) && (xfml != 0)){				//△T10 2014.01.15 [N.Takayama]
if ((vspcmd <= (LONG)h30spcmd) && (!(xvfml & BIT31) *-1)){
	psdsstp = (ULONG)-1;	//YES;
}
if (!(vspcmd <= (LONG)h30spcmd)){
	psdsstp = 0;	//NO;
}
//*****@ed_psdsstp
//*****@st_v10h,v10l,vspmod,psdsstp,vspcmd
ulwk0 = psdsstp & (!(p900dzps > (LONG)hsdsdzps) -1) & vxdz;
ulwk1 = ulwk0 & (!(vspcmd - vspcmd / (LONG)hdcstopwk > (LONG)hdcstop) * -1);	//着床ﾚﾍﾞﾙﾊﾞﾗﾂｷ改善
ulwk2 = ulwk0 & (!(vspcmd - vspcmd / (LONG)hdcstopwk > (LONG)hdcstop) -1);	//着床ﾚﾍﾞﾙﾊﾞﾗﾂｷ改善
if (ulwk1){
	v10h = 0;
	v10l = 0;
	vspmod = 0;
	psdsstp = 0;
	vspcmd = 0;
}
if (ulwk2){
	vspcmd = vspcmd - vspcmd / (LONG)hdcstopwk;		//着床ﾚﾍﾞﾙﾊﾞﾗﾂｷ改善
}
//*****@ed_v10h,v10l,vspmod,psdsstp,vspcmd
//*****@ed_v6dd0l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6de0l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*		     <1>: 						 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6de0l)                                               */
/************************************************************************/
extern "C" ULONG rv6de0l(void);
ULONG rv6de0ls(void){
//ユーザー用ワーク

//*****@st_v6de0l
//*****@st_vhybsdtm							//HYB ｽﾄｯﾌﾟﾚｽ強制減速回路
*vhybsdtm = cvhybsdtm.cmt((ULONG)-1);	//YES
//*****@ed_vhybsdtm
//*****@st_vhybsd
vhybsd = (!(vstat & BIT7) * -1) & v10h;
//*****@ed_vhybsd
vbatmod = ~cvhybsdtm.dmt() & vh97bp & (!(hhyb & BIT31)-1);
//*****@st_vhybsdcc
if (!cvhybsdtm.dmt() && !vhybsd){
	vhybsdcc = (LONG)hsdsdcc3;
}
if (!cvhybsdtm.dmt() && vhybsd){
	vhybsdcc = (LONG)hsdsdcc3;
}
if (cvhybsdtm.dmt()){
	vhybsdcc = (LONG)hsdsdcc2;
	vhybcosd = (ULONG)-1;			//test
}
//*****@ed_vhybsdcc
//*****@st_vspcmd
if (vspcmd > (LONG)vspcmdhy){
	vspcmd = vspcmd - vhybsdcc;
	if (((LONG)vspcmdhy >= h15spcmd) && (vspcmd < h15spcmd)){
		vspcmd = h15spcmd;
	}
}
else{
	if (!zv92 && (xhcpcd1 & BIT4)){
		*vbatdrvt = cvbatdrvt.cmt((ULONG)-1);
		if (cvbatdrvt.tmt() && !cvbatdrvt.dmt()){
			vhybcosd = (ULONG)-1;		//test
		}			
		else{
			vhybcosd = 0;				//test
		}
		if (hhyb & BIT2){
			if (((xvhybid1 + xvhybid2) > (LONG)hibatlim) && (vspcmd >= h15spcmd)){
				vbatovc1 += 1;
				vbatov1 += vabssign((xvhybid1 + xvhybid2),(LONG)hibatlim);
				if (vbatovc1 > 100){
					vbatov1 = vbatov1 / (LONG)hibatlim;
					vspcmdb1 = vbatov1 * vspcmd / 100;
					vspcmd = vspcmd - vspcmdb1;
					vbatovc1 = 0;
					vbatov1 = 0;
				}
			}
			else {
				vbatovc1 = 0;
				vbatov1 = 0;
			}
		}
		else{
			if ((xvhybid1 > (LONG)hibatlim) && (vspcmd >= h15spcmd)){
				vbatovc1 += 1;
				vbatov1 += vabssign((xvhybid1 + xvhybid2),(LONG)hibatlim);
				if (vbatovc1 > 100){
					vbatov1= vbatov1 / (LONG)hibatlim;
					vspcmdb1 = vbatov1 * vspcmd / 100;
					vspcmd = vspcmd - vspcmdb1;
					vbatovc1 = 0;
					vbatov1 = 0;
				}
			}
			else {
				vbatovc1 = 0;
				vbatov1 = 0;
			}
		}
		if (cvbatdrvt.dmt() && (vspcmd < h15spcmd)){
			vspcmd = h15spcmd;
			vh06spcmd = (ULONG)-1;
		}
	}
}
//*****@ed_vspcmd
if ((hhyb & BIT31) && vh97bp){						//HYB ｽﾄｯﾌﾟﾚｽ減速時ｹﾞｲﾝUP
	if (vhybcosd){
		vasrgon = (ULONG)-1;
		vasrgin = 600;
	}
	else{
		vasrgon = 0x0;
		vasrgin = 0x400;
	}
}
//*****@ed_v6de0l
return (ULONG)-1;
}

/*************************************************************************
* NAME              =b14v6df0l.cpp										 *
* FUNCTION          =従ソフト部											 *
* NOTE              =													 *
* AUTHOR            =M.Furuhashi										 *
* DATE              =2002.05.28											 *
* ORIGINAL          =(FD No.)											 *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
*                    <1>:												 *
* COPYRIGHT (C) HITACHI,LTD. 2002 ALL RIGHTS RESERVED.                   *
**************************************************************************
* ｿｰｽ FD No    :                                                         *
*************************************************************************/
#define LOOP_DUMMY 999
/*************************************************************************
* プロトタイプ宣言                                                       *
*************************************************************************/

/************************************************************************/
/*     シーケンス(v6df0l)                                               */
/************************************************************************/
extern "C" ULONG rv6df0l(void);
ULONG rv6df0ls(void){
//ユーザー用ワーク
//*****@st_v6df0l

//*****@ed_v6df0l
return (ULONG)-1;
}
