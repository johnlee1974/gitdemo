#include "b25v_base___com_000.h"

#include "../../B25z_base00/inc/b25z_base00_ra1_000.h"
#include "../../B25z_base00/inc/b25z_base00_ra2_000.h"
#include "../../B25z_base00/inc/b25z_base00_ras_000.h"
#include "../../B25z_base00/inc/b25z_base00_rabk_000.h"
#include "../../B25z_base00/inc/b25z_base00_sp1_000.h"
#include "../../B25z_base00/inc/b25z_base00_sp2_000.h"

//------<999> 依存関係見直し要

//------- Z   ------

//------- U   ------

//------- Q   ------

//------- l   ------

//------- D   ------

//------<999> 見直し要

/****************************************************************************
* NAME              =b25v6e.cpp											 	*
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

/************************************************************************/
/*     シーケンス(v6e00p)                                               */
/************************************************************************/
extern "C" ULONG v6e00p(void);
ULONG v6e00p(void){
//ユーザー用ワーク
register ULONG ulwk0;
register ULONG ulwk1,ulwk2,ulwk3,ulwk4,ulwk5,ulwk6,ulwk7;
register LONG  lwk0,lwk1,lwk2; 

//
if ((xvfml & 0x80000000) && (p900 == p300) && !p900pdx){
	if (v11 && !v12){
		p900pda = p900psh + 0x5;
		p900pdx = (ULONG)-1;
	}
	if (!v11 && v12){
		p900pda = p900psh - 0x5;
		p900pdx = (ULONG)-1;
	}
}
if ((zxrs22 == 0x80000000) && (p900 == p300) && !p900pdmx){				//<micro停止>
	if (v11 && !v12){
		p900pdm = p900psh;
		p900pdmx = (ULONG)-1;
	}
}
if ((zxrs21 == 0x80000000) && (p900 == p300) && !p900pdmx){				//<micro停止>
	if (!v11 && v12){
		p900pdm = p900psh;
		p900pdmx = (ULONG)-1;
	}
}
if((vxrs22s == 0x80000000) && (p900 == p300) && !p900pdmsx){
	if (v11 && !v12){
		if (vspdfb & BIT15){
			lwk0 = (LONG)(0xFFFF0000 | vspdfb);
		}
		else{
			lwk0 = (LONG)vspdfb;
		}
//↓<017>(3) 2017.06.28 [N.Takayama]
//		vspdfbrs22 = vabssign(lwk0,0)* 0x100 / hspgain;	
        if(hspgain){
		    vspdfbrs22 = vabssign(lwk0,0)* 0x100 / hspgain;	
        }
        else{
		    vspdfbrs22 = 0;	
        }
//↑<017>(3) 2017.06.28 [N.Takayama]
		p900pdms = p900psh;
		p900pdmsx = (ULONG)-1;
	}
}

lwk0 = p900pdms+h105upm/2;
if(v11 && (p900psh > lwk0)){
		if (vspdfb & BIT15){
			lwk0 = (LONG)(0xFFFF0000 | vspdfb);
		}
		else{
			lwk0 = (LONG)vspdfb;
		}
//↓<017>(3) 2017.06.28 [N.Takayama]
//		vspdfbhf22 = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        if(hspgain){
		    vspdfbhf22 = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        }
        else{
		    vspdfbhf22 = 0;
        }
//↑<017>(3) 2017.06.28 [N.Takayama]
}

if((vxrs21s == 0x80000000)  && (p900 == p300) && !p900pdmsx){
	if (!v11 && v12){
		if (vspdfb & BIT15){
			lwk0 = (LONG)(0xFFFF0000 | vspdfb);
		}
		else{
			lwk0 = (LONG)vspdfb;
		}
//↓<017>(3) 2017.06.28 [N.Takayama]
//		vspdfbrs21 = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        if(hspgain){
		    vspdfbrs21 = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        }
        else{
		    vspdfbrs21 = 0;
        }
//↑<017>(3) 2017.06.28 [N.Takayama]
		p900pdms = p900psh;
		p900pdmsx = (ULONG)-1;
	}
}

lwk0 = p900pdms-h105dnm/2;
if(v12 && (p900psh < lwk0)){
		if (vspdfb & BIT15){
			lwk0 = (LONG)(0xFFFF0000 | vspdfb);
		}
		else{
			lwk0 = (LONG)vspdfb;
		}
//↓<017>(3) 2017.06.28 [N.Takayama]
//		vspdfbhf21 = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        if(hspgain){
  		    vspdfbhf21 = vabssign(lwk0,0)* 0x100 / hspgain;		//vspdfb記録(m/min)
        }
        else{
  		    vspdfbhf21 = 0;
        }
//↑<017>(3) 2017.06.28 [N.Takayama]
}

//
//*****@st_vcwtbz
//	ulwk1 = rmyesnos(iintf & BIT6) & rmyesnos(h10sys(7) & BIT7) & x900rp & ~xftp900ps & rmyesnos(tp900r & BIT31);	//工事中一時停止条件追加 2014.07.16[D.Chen]//条件見直し2014.08.07[D.Chen]
	ulwk1 = (!(h10sys(7) & BIT7)-1) & x900rp & ~xftp900ps & (!(tp900r & BIT31)-1);
//if (~rmyesnos(tp900r & BIT1) && ~p49fm && ~rmyesnos(tp900ps & BIT31) && (((heepromg[81] != 0) && (heepromg[81] != 0xFFFFFFFF) && ((ipm300pt[ipm300] - 0x01000000) > hcwtbzst)) ||	//工事中条件バイパスulwk1追加 2014.07.16[D.Chen]
//	(((heepromg[81] == 0) || (heepromg[81] == 0xFFFFFFFF)) && (ipm300pt[ipm300] > 0x010036B0)) || hcwt11)){ //△S11 変更 2014.03.04[Y.Sugiyama]
//if (((~rmyesnos(tp900r & BIT1) && ~rmyesnos(tp900ps & BIT31))|| ulwk1) && ~p49fm && (((heepromg[81] != 0) && (heepromg[81] != 0xFFFFFFFF) && ((ipm300pt[ipm300] - 0x01000000) > hcwtbzst)) ||
//	(((heepromg[81] == 0) || (heepromg[81] == 0xFFFFFFFF)) && (ipm300pt[ipm300] > 0x010036B0)) || icwt11)){  //<019> CwtブザーOU-14G適用拡大(ST条件,UA-14G条件削除) 17.09.19 [T.Matsukuma]
if (((~rmyesnos(tp900r & BIT1) && ~rmyesnos(tp900ps & BIT31))|| ulwk1) && ~p49fm){
	if(!ulwk1){										//条件分離追加 2014.07.16[D.Chen]
	lwk1 = (LONG)(((ipm300pt[ipm300] & 0xFFFFF) / 2) - hcwtbzd);		//HBS suport Cwt接近
	lwk2 = (LONG)(((ipm300pt[ipm300] & 0xFFFFF) / 2) + hcwtbzu);
	}else{
	lwk1 = (LONG)((epm300ptop / 2) - hcwtbzd);		//電子安全階高データ使用
	lwk2 = (LONG)((epm300ptop / 2) + hcwtbzu);
	}	
	if (icwbz && v10c && v11){
//		vcwtbz = (!(p900psh > lwk1)-1) & (!(p900psh < (lwk1 + 0xFA0))-1);	//工事AN中条件分離 2014.07.16[D.Chen]	
//	   if(!ulwk1) vcwtbz = (!(p900psh > lwk1)-1) & (!(p900psh < (lwk1 + 0xFA0))-1);		//<024>G_Select14 ブザー鳴動範囲切替 2018.04.25[K.Sakai]
	   if(!ulwk1) vcwtbz = (!(p900psh > lwk1)-1) & (!(p900psh < (lwk1 + (LONG)hcwtbzu1))-1);
//	   else       vcwtbz = (!((LONG)pcpsh > lwk1)-1) & (!((LONG)pcpsh < (lwk1 + 0xFA0))-1);	//<024>G_Select14 ブザー鳴動範囲切替 2018.04.25[K.Sakai]
	   else       vcwtbz = (!((LONG)pcpsh > lwk1)-1) & (!((LONG)pcpsh < (lwk1 + (LONG)hcwtbzu1))-1);
	}
	else if (icwbz && v10c && v12){	
//		vcwtbz = (!(p900psh > (lwk2 - 0xFA0))-1) & (!(p900psh < lwk2)-1);	//工事AN中条件分離 2014.07.16[D.Chen]	
//	   if(!ulwk1) vcwtbz = (!(p900psh > (lwk2 - 0xFA0))-1) & (!(p900psh < lwk2)-1);		//<024>G_Select14 ブザー鳴動範囲切替 2018.04.25[K.Sakai]
	   if(!ulwk1) vcwtbz = (!(p900psh < lwk2)-1) & (!(p900psh > (lwk2 - (LONG)hcwtbzd1))-1);
//	   else       vcwtbz = (!((LONG)pcpsh > (lwk2 - 0xFA0))-1) & (!((LONG)pcpsh < lwk2)-1);	//<024>G_Select14 ブザー鳴動範囲切替 2018.04.25[K.Sakai]
	   else       vcwtbz = (!((LONG)pcpsh < lwk2)-1) & (!((LONG)pcpsh > (lwk2 - (LONG)hcwtbzd1))-1);
	}
	else{
		vcwtbz = 0;
	}		
}
else{
	vcwtbz = 0;
}
//*****@ed_vcwtbz
//*****@st_vcwtstp
	if(!ulwk1){										//条件分離追加 2014.07.16[D.Chen]
	lwk1 = (LONG)(((ipm300pt[ipm300] & 0xFFFFF) / 2) - hcwtbzd);
	lwk2 = (LONG)(((ipm300pt[ipm300] & 0xFFFFF) / 2) + hcwtbzu);
	}else{								
	lwk1 = (LONG)((epm300ptop / 2) - hcwtbzd);		//電子安全階高データ使用
	lwk2 = (LONG)((epm300ptop / 2) + hcwtbzu);
	}	
//	if (~rmyesnos(tp900r & BIT1) && ~p49fm && ~rmyesnos(tp900ps & BIT31) && icwbz ){	//工事中一時停止条件追加 2014.07.16[D.Chen]
	if (((~rmyesnos(tp900r & BIT1)  && ~rmyesnos(tp900ps & BIT31))||ulwk1) && ~p49fm && icwbz ){
//		vcwtstp = (!(p900psh > lwk1)-1) & (!(p900psh < lwk2)-1);			//工事AN中条件分離 2014.07.16[D.Chen]	
	  if(!ulwk1) vcwtstp = (!(p900psh > lwk1)-1) & (!(p900psh < lwk2)-1);
	  else       vcwtstp = (!((LONG)pcpsh > lwk1)-1) & (!((LONG)pcpsh < lwk2)-1);
	}else{
		vcwtstp = 0;
	}
//*****@ed_vcwtstp
//ulwk0 = ~rmyesnos(tp900r & BIT1) & ~p49fm & ~rmyesnos(tp900ps & BIT31) & icwbz;		//工事中一時停止条件追加 2014.07.16[D.Chen]		
ulwk0 = ((~rmyesnos(tp900r & BIT1)  & ~rmyesnos(tp900ps & BIT31)) | ulwk1) & ~p49fm & icwbz;
//*****@st_v61flstp 
if((h61flstpd == 0) || (h61flstpd == 0xFFFFFFFF)){//up走行時、ﾍｯﾄﾞとの距離ｽﾍﾟｯｸ
	lwk1 = 0xED8;//3800(mm)
}else{
	lwk1 = h61flstpd;
}
//lwk2 = ipm300pt[ipm300] - 0x01000000;			//工事AN中条件分離 2014.07.16[D.Chen]	
if(!ulwk1) lwk2 = ipm300pt[ipm300] - 0x01000000;
else       lwk2 = epm300ptop;
//v61flstp = ulwk0 & (!((lwk2 - lwk1) < p900psh)-1);//up走行時、現在位置は(ﾍｯﾄﾞ-lwk1)値に侵入検出	//工事AN中条件分離 2014.07.16[D.Chen]
if(!ulwk1) v61flstp = ulwk0 & (!((lwk2 - lwk1) < p900psh)-1);
else       v61flstp = ulwk0 & (!((lwk2 - lwk1) < (LONG)pcpsh)-1);
//*****@ed_v61flstp //
//*****@st_v62flstp //
if((h62flstpd == 0) || (h62flstpd == 0xFFFFFFFF)){//dn走行時、ﾋﾟｯﾄとの距離ｽﾍﾟｯｸ
	lwk1 = 0xC80;//3200(mm)
}else{
	lwk1 = h62flstpd;
}

//v62flstp = ulwk0 & (!(p900psh < lwk1)-1);//dn走行時、現在位置は(lwk1)値に侵入検出	//工事AN中条件分離 2014.07.16[D.Chen]	
if(!ulwk1) v62flstp = ulwk0 & (!(p900psh < lwk1)-1);
else       v62flstp = ulwk0 & (!((LONG)pcpsh < lwk1)-1);
//*****@ed_v62flstp //
//*****@st_v61flstpq //
if((h61flstpq == 0) || (h61flstpq == 0xFFFFFFFF)){//up走行時、全行程がｽﾍﾟｯｸ以下の場合一時停止を禁止
	lwk1 = 0;//0mm(制限無し)
}else{
	lwk1 = h61flstpq;
}
//lwk2 = ipm300pt[ipm300] - 0x01000000;			//工事AN中条件分離 2014.07.16[D.Chen]	
if(!ulwk1) lwk2 = ipm300pt[ipm300] - 0x01000000;
else       lwk2 = epm300ptop;
v61flstpq  = ulwk0 & (!(lwk2 <= lwk1)-1);
//*****@ed_v61flstpq //
//*****@st_v62flstpq //
if((h62flstpq == 0) || (h62flstpq == 0xFFFFFFFF)){//dn走行時、全行程がｽﾍﾟｯｸ以下の場合一時停止を禁止
	lwk1 = 0x2AF8;//11000(mm)
}else{
	lwk1 = h62flstpq;
}
//lwk2 = ipm300pt[ipm300] - 0x01000000;			//工事AN中条件分離 2014.07.16[D.Chen]	
if(!ulwk1) lwk2 = ipm300pt[ipm300] - 0x01000000;
else       lwk2 = epm300ptop;
v62flstpq  = ulwk0 & (!(lwk2 <= lwk1)-1);
//*****@ed_v62flstpq 
//*****@st_vcnst
ulwk0 = zaalp & v10l;
if (ulwk0 && cv10ct.dmt() && v100){
	if(hvsys(4) & BIT3){
		if(!cvalpchkm.dmt()){			//ALPﾊﾞｯﾃﾘﾁｪｯｸ運転
			vcnst = halpcnst;		//2m/minでは回生効率がﾏｲﾅｽ（電力は力行）になるため、速度UPする
		}else{
			vcnst = halpcnst;
		}
	}else{
			vcnst = halpcnst;
	}
}
if (ulwk0 && ((cv10ct.dmt() && !v100) || !cv10ct.dmt())){
	vcnst = halpcns2;
}
ulwk0 = ~zaalp & za10l & v10l;
if (ulwk0 && cv10ct.dmt() && v100){
	vcnst = hslcnst;
}
if (ulwk0 && ((cv10ct.dmt() && !v100) || !cv10ct.dmt())){
	vcnst = hslcnst2;
}
ulwk0 = ~zaalp & ~za10l & za10c;
if (ulwk0 && v10c){
	if (dx17){
		vcnst = h17cnst;
	}
	else if (vxdzdd){
		vcnst = hslcnst2;
	}
	else{
		vcnst = hslcnst;
	}
}
//*****@ed_vcnst
//*****@st_vspw
ulwk0 = v10l & cv10ct.dmt() & v100 & ~zaalp;
if (ulwk0){
//	ulwk1 = (ULONG)((!(!(v12 & xsds1d) && !(v11 & xsds1u)))-1);
	ulwk1 = (ULONG)((!(!(v12 & xsds1d) && !(v11 & xsds1u)))-1) & (~p49fm | (!(pmstat & BIT2) -1));	//TB3-0016 階高測定スタート補正前5m/min化 H.Sakamoto
//	if(ulwk1){		//<024>99E速度15m/min固定 2018.04.25[K.Sakai]
	if(ulwk1 || (hflspat & hlmspd15)){
		vspw = h15spcmd;
	}
	else{
		vspw = h10spcmd;
//↓電子安全位置測定用 2013.11.07 [N.Takayama]  //△S19 削除 2014.04.14[Y.Sugiyama]
//		if(udummy01 == 0xA5A55A5A){
//			vspw = h15spcmd;
//		}
//		else{
//			vspw = h10spcmd;
//		}
//↑電子安全位置測定用 2013.11.07 [N.Takayama]
	}
}
ulwk0 = v10l & cv10ct.dmt() & v100 & zaalp;
if (ulwk0){
	if (zvasalp && !(hhyb & BIT31)){		//HYB ｽﾄｯﾌﾟﾚｽ制御
		vspw = h15spcmd;
	}
	else{
	if(hvsys(4) & BIT3){
		if(!cvalpchkm.dmt()){			//ALP低速運転
			vspw = h10spcmd;		//2m/minでは回生効率がﾏｲﾅｽ（電力は力行）になるため、速度UPする。
			*valpchkm = cvalpchkm.cmt(YES);	//5.0s
			*valpchkf = cvalpchkf.cmt(YES);	//3.5s
		}else{					//ALP通常運転
			if (!xsds1d && !xsds1u){
				vspw = halpsp1;
			}
			if ((!xsds1d && xsds1u) || (xsds1d && !xsds1u)){
				vspw = h10spcmd;
			}
		}
	}else{
			if (!xsds1d && !xsds1u){
				vspw = halpsp1;
			}
			if ((!xsds1d && xsds1u) || (xsds1d && !xsds1u)){
				vspw = h10spcmd;
			}
		}
	}
}
if(hvsys(4) & BIT3){
	ulwk0 = valpchkm[0] & ~cvalpchkm.dmt() & cvalpchkf.dmt();
	if(ulwk0){
		if(valptrqc <= 100){
			if (vtrqcmd & BIT15){
				lwk1 = (LONG)(vtrqcmd | 0xFFFF0000);
			}else{
				lwk1 = (LONG)vtrqcmd;
			}
			valptrqz += lwk1;	//1s間積算
			valptrqc += 1;
		}else{				//1s経過後、ﾁｪｯｸ処理
			if((v11 && ((LONG)valptrqz > (LONG)hapltrqlm)) || (v12 && ((LONG)valptrqz < (0-(LONG)hapltrqlm)))){
				valptrqng = (ULONG)-1;
			}
		}
	}else{
		valptrqz = 0;	//ﾁｪｯｸ運転以外では積算値ｸﾘｱ
		valptrqc = 0;	//ﾁｪｯｸ運転以外では積算ｶｳﾝﾀ値ｸﾘｱ
	}
	if ((!v10l && !v10c) || !v100){	//低速運転停止でｸﾘｱ
		if(valptrqng){
			*(wrbh + 3) += 1;
		}
		cvalpchkm.cmt(0);
		cvalpchkf.cmt(0);
		valptrqng = 0;
	}
}
ulwk0 = v10l & ((cv10ct.dmt() & ~v100) | ~cv10ct.dmt());
if (ulwk0){
	if (zaalp){
		vspw = halpsp2;
	}
	else{
		vspw = h02spcmd;
	}
}
//
lwk1 = (LONG)(((ipm300pt[ipm300] & 0xFFFFF) / 2) - heqcpsl);					//地震Cwt低速
lwk2 = (LONG)(((ipm300pt[ipm300] & 0xFFFFF) / 2) + heqcpsu);
veqcps = zv44eqs40 & v10c & (!(p900psh > lwk1)-1) & (!(p900psh < lwk2)-1);
//					 
ulwk0 = ~v10l & v10c & cv10ct.dmt() & v100;
ulwk1 = ulwk0 & (!(vaspdcd >= 0x14) * -1);
//ulwk2 = ulwk1 & ~xsds1d & ~xsds1u;			//<024>99E速度15m/min固定 2018.04.25[K.Sakai]
//ulwk2 = ulwk1 & ((~xsds1d & ~xsds1u) | (hflspat & hlmspd15));
//ulwk2 = ulwk1 & ((~xsds1d & ~xsds1u) | (hflspat & hlmspd15));  //<033>かご上作業安全確保のための制御改善 2022.07.21 [Y.Saito]
ulwk2 = ulwk1 & (((~xsds1d & ~xsds1u) & (~vbrtrqt/* | vbrtrqs*/)) | (hflspat & hlmspd15)) & ~zvmcsu;  //<035> <D037>
//ulwk3 = ulwk1 & ((~xsds1d & xsds1u) | (xsds1d & ~xsds1u));			//<024>99E速度15m/min固定 2018.04.25[K.Sakai]
//ulwk3 = ulwk1 & ((~xsds1d & xsds1u) | (xsds1d & ~xsds1u)) & ~(hflspat & hlmspd15);
//ulwk3 = ulwk1 & ((((~xsds1d & xsds1u) | (xsds1d & ~xsds1u)) & ~(hflspat & hlmspd15)) | zvmcsu);  //<035> <D037>
//ulwk3 = ulwk1 & ((((~xsds1d & xsds1u) | (xsds1d & ~xsds1u) | (vbrtrqt/* & ~vbrtrqs*/)) & ~(hflspat & hlmspd15)) | zvmcsu);
ulwk3 = ulwk1 & ((((~xsds1d & xsds1u) | (xsds1d & ~xsds1u) | (vbrtrqt/* & ~vbrtrqs*/)) & ~(hflspat & hlmspd15)) | zvmcsu | xftovs | xfttrip);
//ulwk4 = ulwk1 & (veqcps | (zv44eqs40/*地震復旧運転信号*/ & (!(ivtrqchf == 0xA5A55A5A)-1) & ~vsp15rf));	//引っ掛り検出方式変更対応 復旧運転は5m/minｽﾀｰﾄ//<V13>	//<024>16Tから移植 2018.04.25[K.Sakai]
ulwk4 = ulwk1 & (veqcps | (zv44eqs40/*地震復旧運転信号*/ & (!(ivtrqchf == 0xA5A55A5A)-1) & ~vsp15rf & (~rmyesnos(hmrsp & BIT31) | ~rmyesnos(hmrsp & BIT3))));	//引っ掛り検出方式変更対応 復旧運転は5m/minｽﾀｰﾄ
if (ulwk0 && vxdzdd){
	vspw = h02spcmd;
}
if (!v10l && !v10c){
	vspw = 0;
}
if (ulwk0 && (vaspdcd >= 0x14) && !vxdzdd){ 
	vspw = h30spcmd;
}
if (ulwk2 && !vxdzdd){
//	vspw = h15spcmd;  //<020> 2018.01.04 [Y.Saito]
    if (!htst_modeh || (vmicrotmd != 0xA55A5AA5)){
        vspw = h15spcmd;
    }
    else {
        vspw = h30spcmd;
    }
}
if ((ulwk3 || ulwk4) && !vxdzdd){     	//地震Cwt低速
//	vspw = h10spcmd;  //<020> 2018.01.04 [Y.Saito]
    if (!htst_modeh || (vmicrotmd != 0xA55A5AA5)){
        vspw = h10spcmd;
    }
    else {
        vspw = h30spcmd;
    }
//↓電子安全位置測定用 2013.11.07 [N.Takayama]  //△S19 削除 2014.04.14[Y.Sugiyama]
//		if(udummy01 == 0xA5A55A5A){
//			vspw = h15spcmd;
//		}
//		else{
//			vspw = h10spcmd;
//		}
//↑電子安全位置測定用 2013.11.07 [N.Takayama]
}
//*****@ed_vspw
//*****@st_vdzln
if(!xsds1u && !xsds1d){		//端階99E時着床ﾚﾍﾞﾙ改善
//	vdzln = hdzln;			//削除 2014.08.18[H.Fukata]
//各階遮蔽板調整追加↓*/			//2014.08.18[H.Fukata]
	ulwk1 = (hmcrb2 & 0x00FF);
	if(ulwk1 & BIT7){	//ﾏｲﾅｽだったら
		ulwk1 = 0x100 - ulwk1;	//byte単位での符号反転
		vdzln = hdzln + ulwk1;
	}else{
		vdzln = hdzln - ulwk1;
	}
}else{
//	vdzln = hdzln + 10;
	ulwk1 = (hmcrb2 & 0x00FF);
	if(ulwk1 & BIT7){	//ﾏｲﾅｽだったら
		ulwk1 = 0x100 - ulwk1;	//byte単位での符号反転
		vdzln = hdzln + 10 + ulwk1;
	}else{
		vdzln = hdzln + 10 - ulwk1;
	}
}
//各階遮蔽板調整追加↑*/			//2014.08.18[H.Fukata]
//*****@ed_vdzln
//*****@st_vcnst,vdzln,vspw
//ulwk0 = (!(h10sys(1) & BIT3) -1) & v16;//<014> 荷物用対応 
ulwk0 = ((!(h10sys(1) & BIT3) -1) | (hincma & ~xincat)) & v16;
if (ulwk0){
	vcnst = hmcnst;
}
if (ulwk0){
	if (v16up || (!v16up && !v16dn)){
		if (h10sys(4) & BIT5){
			vdzln = h16ln;
			if((LONG)vdzln < 0) vdzln = 1;
		}
		else{
			vdzln = h16lnp;
			if((LONG)vdzln < 0) vdzln = 1;
		}
	}
	if (!v16up && v16dn){
		if (h10sys(4) & BIT5){
			vdzln = h16lnp;
			if((LONG)vdzln < 0) vdzln = 1;
		}
		else{
			vdzln = h16ln;
			if((LONG)vdzln < 0) vdzln = 1;
		}	
	}
}
//ulwk1 = ulwk0 & (!((LONG)vdzln >= p900dzps) -1) & v16up;//<014> 荷物用対応 
ulwk1 = ulwk0 & ((!((LONG)vdzln >= p900dzps) -1) | ~xincat) & v16up;
//ulwk2 = ulwk0 & (!((LONG)vdzln >= p900dzps) -1) & ~v16up & ~v16dn;//<014> 荷物用対応 
ulwk2 = ulwk0 & ((!((LONG)vdzln >= p900dzps) -1) | ~xincat) & ~v16up & ~v16dn;
//ulwk3 = ulwk0 & (!((LONG)vdzln >= p900dzps) -1) & ~v16up & v16dn;//<014> 荷物用対応 
ulwk3 = ulwk0 & ((!((LONG)vdzln >= p900dzps) -1) | ~xincat) & ~v16up & v16dn;
if (ulwk1){
	ulwk4 = (h16cmd / 0x100) + h16cmdadj;
}
if (ulwk2){
	ulwk4 = 0xFF + h16cmdadj;
}
if (ulwk3){
	ulwk4 = (h16cmd & 0xFF) + h16cmdadj;
}
//if (ulwk0 && (!((LONG)vdzln >= p900dzps) -1)){//<014> 荷物用対応 
if (ulwk0 && ((!((LONG)vdzln >= p900dzps) -1) || ~xincat)){
	if (ulwk4 != 0){
		vspw = ulwk4;
		if (vspw >= h16splm){
			vspw = h16splm;
		}
	}
	else{
		vspw = 0xFF;
	}
}
//*****@ed_vcnst,vdzln,vspw
//*****@st_p900pshd
if (!v10 && !v15b){
	p900pshd = p900psh;
}
//*****@st_p900pshd
ulwk6 = 0;
ulwk7 = 0;
//*****@st_vspcmd,v15b,vabrans,v10l
ulwk0 = ~v10h & cv10ct.dmt();
ulwk1 = ((~v10h & ~cv10ct.dmt()) | v10h) & (!(h10sys(1) & BIT3) -1) & v16;
ulwk6 = (!(ulwk0 & BIT31) -1) & v10c;
if (ulwk6){
	if (!zopfsen1 || (zopfsen1 && !zopfsen2)){
		ulwk7 = (ULONG)-1;
		vxdzdd = 0;
	}
	if (zopfsen1 && zopfsen2){
		if (!z90p00){ 
			if (zddopcd & BIT0){
				if (vxdz){
					vddopd = (LONG)hddopcd0;
				}
				else{
					vddopd = (LONG)hddopcd0 - 600;
				}
			}
			if (zddopcd & BIT2){
				vddopd = (LONG)hddopcd2 + (LONG)hddlnadj;
			}
			if (zddopcd & BIT3){
				vddopd = (LONG)hddopcd3 + (LONG)hddlnadj;
			}
		}
		if (v11){
			ulwk7 = (!(zddopcd & BIT0)-1) & ((!((p900pshd + vddopd) >= p900psh) -1) | vxdz);
			ulwk7 = ulwk7 | ((!(zddopcd & BIT2)-1) & (~vxdz | (vxdz & ((!(p900 == p900dr)* -1) | ((!(p900 == p900dr) -1) & (!(p900dzps <= vdzln) -1))) )));
			ulwk7 = ulwk7 | ((!(zddopcd & BIT4)-1) & ~vxdz);
			if ((zddopcd & BIT2) && vxdz && (!(p900 == p900dr) -1)){
				vxdzdd = (ULONG)-1;
			}
		}
		if (v12){
//			ulwk7 = (!(zddopcd & BIT1)-1) & ~xsds1d;//<021>
//			ulwk7 = (!(zddopcd & BIT1)-1) & (~xsds1d | (xsds1d & (rmyesnos(hmrsp & BIT31) & rmyesnos(hmrsp & BIT4) & (~vxdz | (vxdz & (!(p900dzps <= vdzln)-1))))));  //<035> <D062>
			ulwk7 = (!(zddopcd & BIT1)-1) & (~xmlsd | (xmlsd & (rmyesnos(hmrsp & BIT31) & rmyesnos(hmrsp & BIT4) & (~vxdz | (vxdz & (!(p900dzps <= vdzln)-1))))));
//			ulwk7 = ulwk7 | ((!(zddopcd & BIT3)-1) & ((!((p900pshd - vddopd) <= p900psh) -1) | vxdz));//<021>
			ulwk7 = ulwk7 | ((~rmyesnos(hmrsp & BIT31) | ~rmyesnos(hmrsp & BIT4)) & (!(zddopcd & BIT3)-1) & ((!((p900pshd - vddopd) <= p900psh) -1) | vxdz));
			ulwk7 = ulwk7 | (rmyesnos(hmrsp & BIT31) & rmyesnos(hmrsp & BIT4) & ~xdls & (!(zddopcd & BIT3)-1) & ((!((p900pshd - vddopd) <= p900psh) -1) | vxdz));
//			ulwk7 = ulwk7 | ((!(zddopcd & BIT4)-1) & ~xsds1d);//<021>
//			ulwk7 = ulwk7 | ((!(zddopcd & BIT4)-1) & (~xsds1d | (xsds1d & rmyesnos(hmrsp & BIT31) & rmyesnos(hmrsp & BIT4) & ~vxdz)));  //<035> <D062>
			ulwk7 = ulwk7 | ((!(zddopcd & BIT4)-1) & (~xmlsd | (xmlsd & rmyesnos(hmrsp & BIT31) & rmyesnos(hmrsp & BIT4) & ~vxdz)));
//			if ((zddopcd & BIT1) && xsds1d && vxdz){	//DN時レベルまで運転//<021> <035> <D062>
			if ((zddopcd & BIT1) && xmlsd && vxdz){
				vxdzdd = (ULONG)-1;                     //<021>
			}                                               //<021>
		}
	}
	vcaccf = ulwk7;
}																			
ulwk2 = ((!(ulwk0 & BIT31) -1) & ((~v10c & z100) | (~v10c & ~z100 & ~v10l))) | (ulwk6 & vcaccf);
//ulwk3 = (!(ulwk0 & BIT31) -1) & ~v10c & ~zv100 & v10l;
ulwk3 = (!(ulwk0 & BIT31) -1) & ~v10c & ~zv100 & v10l & (~zvdxfms | ~v12);	//階高測定準備時はDLS検知まで停止させず TB3-0010 H.Sakamoto
ulwk6 = ~xincat & ~v10 & ~v16up & ~v16dn;//<014> 荷物用対応 
ulwk4 = (ulwk1 | ulwk3) & (!((LONG)vdzln >= p900dzps) -1);
ulwk5 = (ulwk1 | ulwk3) & (!((LONG)vdzln >= p900dzps) *-1);
ulwk5 = (ulwk5 & xincat) | ulwk6;//<014> 荷物用対応 
ulwk4 = (ulwk4 | ~xincat) & ~ulwk6;//<014> 荷物用対応 
ulwk5 = ulwk5 | (v10c & zopfsen1 & zopfsen2 & ~vcaccf & cv10ct.dmt());													//<HBS suport> 06.10.16 M
//if (ulwk2 || ulwk4){ //<035> <D090><V28> 同期駆動システム追加 2016.11.15 T.Terunuma
if ((ulwk2 || ulwk4) && (vsdmode != 0xA5A55A5A))  {
	vspcmd += (((LONG)vspw - vspcmd) * (LONG)vcnst / 0x10000);
}
lwk0 = 0;
if (ulwk5){
	if ((hdcstop == 0)){
		lwk0 = 0;
	}
	else{
		lwk0 = vabssign((vspcmd / (LONG)hdcstop) , 0);
	}

	if (!((LONG)hdcstop < (vspcmd - lwk0))){
		vspcmd = 0;
		v15b = 0;							//ﾌﾞﾚｰｷﾁｮｯﾊﾟ v15bsw1とOFF同期
		vabrans = (ULONG)-1;
		v10l = 0;
		v16nh = 0;							//ﾏｲｸﾛ建築基準法対応
		v15bswa1 = 0;							//ﾌﾞﾚｰｷﾁｮｯﾊﾟ
		v15bswa2 = 0;
		v15bswb1 = 0;							//ﾌﾞﾚｰｷﾁｮｯﾊﾟ
		v15bswb2 = 0;
		if (zopfsen2){
			v10c = 0;
			vxdzdd = 0;
		}
	}
	if ((LONG)hdcstop < (vspcmd - lwk0)){
		vspcmd -= lwk0;
	}
}
//*****@ed_vspcmd,v15b,vabrans,v10l
//*****@st_v16nh							//ﾏｲｸﾛ建築基準法対応
if (v10){
	v16nh = 0;
}
else {
	if (v16 && v15b){
		v16nh = (ULONG)-1;
	}
}
//*****@ed_v16nh
//*****@st_tmcrovr							//ﾏｲｸﾛ建築基準法対応
//tmcrovr = v16nh & (!((xvfml & 0xF0000000) == 0x0)-1);
if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
    tmcrovr = v16nh & (!((xvfml & 0xF0000000) == 0x0)-1);
}//<021> 香港UCMP対応
//↓<035> <D090><V12> 同期駆動システム追加 2016.09.13 [T.Terunuma]
if(vsdmode == 0xA5A55A5A){
	if(vsdstep2 == 0xA5A55A5A){
		if((vspcmd + 1) < h15spcmd){
			vspcmd += 1;
		}
		else{
			vspcmd = h15spcmd;
		}
		if(v11 & BIT31){
			vspdrf = (vspcmd * (LONG)hspgain) / 0x100;
		}
		else if(v12 & BIT31){
			vspdrf = -(vspcmd * (LONG)hspgain) / 0x100;
		}
	}
	else{
		vspcmd = 0;
		vspdrf = 0;
	}
}
//↑<035> <D090><V12> 同期駆動システム追加 2016.09.13 [T.Terunuma]
//*****@st_tmcrovr
return (ULONG)-1;
}
