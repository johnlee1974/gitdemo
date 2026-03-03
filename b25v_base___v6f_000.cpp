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
* NAME              =b25v6f.cpp											 	*
* FUNCTION          =従ソフト部											 	*
* NOTE              =                                                    *
* AUTHOR            =                                                    *
* DATE              =2023.11.13                                          *
* ORIGINAL          =(FD No.)                                            *
* HISTORY           =<0>:変更内容 年(西暦4桁).月(2桁).日(2桁) [作成者名] *
* b14z_base01_com(m31)_001 以降適用                                      *
*  <000>:STM32Hxx対応 endian              2024.02.12[T.Hatori]
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
/*     シーケンス(v6f00p)                                               */
/************************************************************************/
//<SAE><09.11.15>Iw SAEﾏｲｸﾛ回路追加	//<00*><10.01.17>Iw
extern "C" ULONG v6f00p(void);
ULONG v6f00p(void){
//register ULONG ulwk0,ulwk1,ulwk2,ulwk3;	//<00*><10.02.05>Iw ulwk2,3追加	//<00*><10.02.12>Iw ulwk1追加
register ULONG ulwk0,ulwk1,ulwk2,ulwk3,ulwk4;			//<V20>ulwk2,3削除 2011.08.03K.Sakai //<035> <D038>
register LONG  lwk0,lwk1,lwk5;	//<00*><09.12.21>Iw lwk1追加
double udwk0;
int a;      //手動ループ変数		//<V20>削除 2011.08.03K.Sakai  //<035> <D038>
ULONG	*p,*q;						//<035> <D038>

/*↓<V20>救出運転回路削除 2011.08.03[K.Sakai]
//<00*><10.02.05>Iw 救出運転右号機回路v6fへ移動ここから
//<00*><10.02.05>Iw 左号機用に2->3にﾃﾞﾊﾞｲｽ変更
if(h10sys(2) & BIT6){
	zx44mbw = zx44mb;
	if(cv97t.dmt()){
		tsaerst |= BIT0;
		tsaerst |= BIT2;
	}
	set_imask(13);
	rsae3 = (unsigned short)tsaerst;
	for (a = 19 ; a >= 0 ; a--){ 	//<00*><10.01.24>Iw ｳｴｲﾄ(1.5μ)
                ulwk0 += 1;
        }
	ulwk3 = (ULONG)rsae3;
	ulwk2 = (ULONG)rsae2;
	set_imask(0);
	xsae3ww = ulwk3 * 0x10000 | ulwk2;
	
	ulwk0 = xsae3ww;
	if(!(irsccmd & BIT8)){
		xsae3w = ulwk0;
	}else{
		xsae3w = ((0 - ulwk0) & 0x00FFFFFF) | (ulwk0 & 0xFF000000);
	}
	tsae3ew = tsae3ew / 2;
	ulwk0 = xsae3w & 0xC8000000;
	if(ulwk0){
		tsae3ew |= BIT31;
		tsae3erc += 1;
		tsae3ec += 1;
	}else{
		lwk0 = (LONG)(vabs((xsae3w * 0x100),xsae3));	//<00*><10.02.21>Iw lwkに一旦落とす
		lwk1 = (LONG)hsaedf;				//<00*><10.02.21>Iw lwkに一旦落とす
//		if((LONG)(vabs((xsae3w * 0x100),xsae3)) > (LONG)hsaedf){	//<00*><10.02.21>Iw lwkに一旦落とす
//		if((vabssign(lwk0,0)) > (vabssign(lwk1,0))){		//<00*><10.02.23>Iw 電源投入直後のｶｳﾝﾄｱｯﾌﾟ対策
		if(((vabssign(lwk0,0)) > (vabssign(lwk1,0))) &&  cvs97t.dmt()){
		
			tsae3erc += 1;
		}
	}
	if(ulwk0){
		if(ulwk0 & BIT30){
			tsae3cmc += 1;
		}else{
			tsae3lbc += 1;
		}
	}
	if(((tsae3ew & 0xE0000000) == 0xE0000000)){
		tsae3e = 0xFFFFFFFF;
	}else{
		tsae3e = 0;
	}
//	ulwk0 = (!(vspcmd == 0) *-1) & zx44mbw & ~z92k;	//<00*><10.03.02>Iw 主->従通信経由
	ulwk0 = (!(vspcmd == 0) *-1) & zx44mbw & ~zv92k;
	if(ulwk0){
		if(vspcmd > (LONG)(h15spcmd * 4)){
			if(v11){
//				v90saw = !(p900psh >= (pcpsb - (LONG)h90sae1)) -1;	//<00*><10.03.02>Iw 訂正h->i
//				v90sa = !(p900psh >= (pcpsb - (LONG)h90sae3)) -1;	//<00*><10.03.02>Iw 訂正h->i
				v90saw = !(p900psh >= (pcpsb - (LONG)i90sae2)) -1;
				v90sa = !(p900psh >= (pcpsb - (LONG)i90sae4)) -1;
			}else{
//				v90saw = !(p900psh <= (pcpsb - (LONG)h90sae1)) -1;	//<00*><10.03.02>Iw 訂正h->i
//				v90sa = !(p900psh <= (pcpsb - (LONG)h90sae3)) -1;	//<00*><10.03.02>Iw 訂正h->i
				v90saw = !(p900psh <= (pcpsb + (LONG)i90sae2)) -1;	//<00*><10.03.04>Iw 訂正-->+
				v90sa = !(p900psh <= (pcpsb + (LONG)i90sae4)) -1;	//<00*><10.03.04>Iw 訂正-->+
			}
		}else{
			if(v11){
//				v90saw = !(p900psh >= (pcpsb - (LONG)h90sae2)) -1;	//<00*><10.03.02>Iw 訂正h->i
//				v90sa = !(p900psh >= (pcpsb - (LONG)h90sae4)) -1;	//<00*><10.03.02>Iw 訂正h->i
				v90saw = !(p900psh >= (pcpsb - (LONG)i90sae1)) -1;
				v90sa = !(p900psh >= (pcpsb - (LONG)i90sae3)) -1;
			}else{
//				v90saw = !(p900psh <= (pcpsb - (LONG)h90sae2)) -1;	//<00*><10.03.02>Iw 訂正h->i
//				v90sa = !(p900psh <= (pcpsb - (LONG)h90sae4)) -1;	//<00*><10.03.02>Iw 訂正h->i
				v90saw = !(p900psh <= (pcpsb + (LONG)i90sae1)) -1;	//<00*><10.03.04>Iw 訂正-->+
				v90sa = !(p900psh <= (pcpsb + (LONG)i90sae3)) -1;	//<00*><10.03.04>Iw 訂正-->+
			}
		}
	}
//	ulwk0 = (!(vspcmd == 0) *-1) & zx44mbw & z92k;	//<00*><10.03.02>Iw 主->従通信経由
	ulwk0 = (!(vspcmd == 0) *-1) & zx44mbw & zv92k;
	if(ulwk0){
		if(v11){
			v15ka = !(p900psh >= (pcpsb - ((LONG)(hrsccmd & 0x000000FF)))) -1;
		}else{
//			v15ka = !(p900psh >= (pcpsb + ((LONG)(hrsccmd & 0x000000FF)))) -1;	//<00*><10.03.05>Iw 訂正
			v15ka = !(p900psh <= (pcpsb + ((LONG)(hrsccmd & 0x000000FF)))) -1;
		}
	}
	if(vspcmd == 0){	//<00*><10.03.02>Iw ｸﾘｱ回路追加
		v90saw = 0;
		v90sa = 0;
		v15ka = 0;
	}
//	if(zx44mbw){		//<00*><10.03.05>Iw 救出DN対応ここから
	if(zx44mbw && !zx44maw){	//<00*><10.03.07>Iw 救出DN対応ここから
		if(pcpsb > p900psh){
			v44sk |= BIT31;	//<00*><10.03.06>Iw 変更
			v44sk &= ~BIT30;	//<00*><10.03.06>Iw 変更
//			v44sk |= BIT29;		//<00*><10.03.07>Iw 訂正
//			v44sk &= ~BIT28;	//<00*><10.03.07>Iw 訂正
		}else{
			v44sk |= BIT30;	//<00*><10.03.06>Iw 変更
			v44sk &= ~BIT31;	//<00*><10.03.06>Iw 変更
//			v44sk |= BIT28;		//<00*><10.03.07>Iw 訂正
//			v44sk &= ~BIT29;	//<00*><10.03.07>Iw 訂正
		}
	}
//	else{
////		v44sk = 0;	//<00*><10.03.06>Iw 変更
//		v44sk &= ~BIT28;
//		v44sk &= ~BIT29;
//	}			//<00*><10.03.05>Iw 救出DN対応ここまで
	if((!zx44maw && !zx44mbw) || (zx44maw && zx44mbw)){	//<00*><10.03.07>Iw 救出DN対応ここから
		v44sk &= ~BIT30;
		v44sk &= ~BIT31;
	}
	if(cvs97t.dmt() && !(tsae3e & BIT31) && !dxfms){
		lwk0 = (LONG)(vabs((xsae3w * 0x100),xsae3));			//<00*><10.02.21>Iw lwkに一旦落とす
		lwk1 = (LONG)hsaedf;						//<00*><10.02.21>Iw lwkに一旦落とす
//		if((LONG)(vabs((xsae3w * 0x100),xsae3)) > (LONG)hsaedf){	//<00*><10.02.21>Iw lwkに一旦落とす
		if((vabssign(lwk0,0)) > (vabssign(lwk1,0))){
			tsae3e |= BIT1;
			tsae3c += 1;
		}else{
			tsae3e &= ~BIT1;
			tsae3c = 0;
		}
	}
//	if(!(xsae3w & BIT30) && !tsae3e && ((!(cv97t.dmt()) && (cv97at.dmt())) || !(tsae3e & BIT1))){
//	if(!(xsae3w & BIT30) && !(tsae3e & BIT31) && ((!(cv97t.dmt()) && (cv97at.dmt())) || !(tsae3e & BIT1))){		//<00*><10.03.02>Iw SAE更新条件厳密化
	if(!(xsae3w & BIT27) && !(xsae3w & BIT30) && !(xsae3w & BIT31) && !(tsae3e & BIT31) && ((!(cv97t.dmt()) && (cv97at.dmt())) || !(tsae3e & BIT1))){
		tsae3c = 0;
		xsae3 = xsae3w * 0x100;
	}
}	//左号機用ここまで
tsaerst &= ~BIT2;	//ﾘｰﾄﾞﾓｰﾄﾞからｱｸﾜｲｱﾓｰﾄﾞへ
if(h10sys(2) & BIT5){
	tsaerst &= ~BIT0;	//左号機読み込みに備える
}
rsae3 = (unsigned short)tsaerst;
//<00*><10.02.05>Iw 救出運転右号機回路v6fへ移動ここまで
*/	//↑<V20>救出運転回路削除 2011.08.03[K.Sakai]

if((h10sys(2) & BIT4) && cv97t.dmt() && !p49fm){
	v10hh |= vstat;
}else{
	v10hh = 0;
}
//if(v10hh){	//<00*><10.02.17>Iw v10hh=vstat.bit15
//if(!(hvsys(4) & BIT7)){			.SAE1 電子安全ｼｽﾃﾑｺｰﾄﾞによるSAEﾏｲｸﾛｶｯﾄ//
if((v10hh & BIT15)){
//	ulwk0 = vabs(plevel,pbtmflh);
//	if(!(h10sys(7) & BIT7)){		//電子安全時pbtmflh=0ｾｯﾄにより統一 2014.07.22[D.Chen]
		lwk0 = vabssign((LONG)plevel,pbtmflh);			//<00*><09.12.16>Iw 定義変更
//	}else{
//		lwk0 = vabssign((LONG)plevel,0);
//	}
	lwk0 = vabssign(lwk0,0);	//<013><11.07.17>Iw 絶対値判定追加
	
//	udwk0 = (double)ulwk0 * (double)hmmunt / 0x1000000;
	udwk0 = (double)lwk0 * (double)hmmunt / 0x1000000;	//<00*><09.12.16>Iw 定義変更
	
	pmczn = (!((LONG)(*(ipm300pt + p900) & 0xFFFFF) + 125 > (LONG)udwk0)-1) & (!((LONG)udwk0 > (LONG)(*(ipm300pt + p900) & 0xFFFFF) - 125)-1);
	
	plverrw = ((LONG)xsae1 - (LONG)plevel) / 0x100;

//	plverra = ((LONG)xsae1 - (LONG)plevel) / 0x40;		//<012><11.06.10>KK UVF5 ﾎﾞｰﾙﾀｲﾌﾟｶﾞﾊﾞﾅ
//	udwk0 = (double)plverra * (double)hgovgain / 0x1000 / 4;
//	plverrw = (LONG)udwk0;

//	plverr += (plverrw - plverr) * (LONG)hsaepcst / 0x10000;	//<00*><09.12.21>Iw 桁あふれ対策+絶対値判定
	if(plverrw > plverr){
		lwk1 = plverrw - plverr;
		udwk0 = (double)lwk1 * (double)hsaepcst / 0x10000;
		plverr += (LONG)udwk0;
	}else{
		lwk1 = plverr - plverrw;
		udwk0 = (double)lwk1 * (double)hsaepcst / 0x10000;
		plverr -= (LONG)udwk0;
	}
/*	if(hsaeunt==0) plverrmm = NO;			//0割り対策  2014.08.07[D.Chen]		//極小値割防止 2014.08.09[D.Chen]
	else{
	plverrmm = ((LONG)xsae1 - (LONG)plevel) / ((LONG)hsaeunt / 0x10000);
	}*/
//追加 ↓ 2014.08.10[D.Chen]
	if(hsaeunt && !tflunu){
		if( 0 != ((LONG)hsaeunt / 0x10000)) {
		plverrmm = ((LONG)xsae1 - (LONG)plevel) / ((LONG)hsaeunt / 0x10000);
    	}else {
			plverrmm = 0;
    	} 							
	}else{
		plverrmm = 0;
	}
//追加 ↑ 2014.08.10[D.Chen]
//<004><10.05.06>Iw SAEﾚﾍﾞﾙずれを主へ送信ここから
	if((vabssign(plverrmm,0)) > (LONG)i16pw){	//ずれ13mm超え
		vlverr = 0xFFFFFFFF;
	}else{				//それ以下
		vlverr = 0;
	}
//<004><10.05.06>Iw SAEﾚﾍﾞﾙずれを主へ送信ここまで
//	if((vabssign(plverrmm,0) > 5) && !vi60supq){		//<00★><10.02.12>Iw test
//		udummy18 |= BIT6;
//	}else{
//		udummy18 &= ~BIT6;
//	}
	
//	psaelvok = !((vabs(xsae1,plevel) / (hsaeunt / 0x10000)) < h16p2)-1;
//	psaelvok = !(((LONG)xsae1 - (LONG)plevel) / ((LONG)hsaeunt / 0x10000) < h16p2)-1;	//<00*><09.12.16>Iw 定義変更
	lwk0 = vabssign((LONG)xsae1,(LONG)plevel);	//<013><11.07.17>Iw 絶対値判定追加
//	psaelvok = !((vabssign((LONG)xsae1,(LONG)plevel)) / ((LONG)hsaeunt / 0x10000) < h16p2)-1;	//<00*><09.12.21>Iw 定義変更
/*	if(hsaeunt==0) psaelvok = NO;				//0割り対策  2014.08.07[D.Chen]	//極小値割防止 2014.08.09[D.Chen]
	else{
	psaelvok = !((vabssign(lwk0,0)) / ((LONG)hsaeunt / 0x10000) < h16p2)-1;	//<013><11.07.17>Iw 絶対値判定追加
	}*/
//追加↓ 2014.08.10[D.Chen]
	if(hsaeunt && !tflunu){
		if( 0 != ((LONG)hsaeunt / 0x10000))	{							
		psaelvok = !((vabssign(lwk0,0)) / ((LONG)hsaeunt / 0x10000) < h16p2)-1;
		}else {
			psaelvok = 0;
		}
	}else{
		psaelvok = 0;
	}
//追加↑ 2014.08.10[D.Chen]
//↓TB3-0016 電子安全Lv4 FML中心位置からのずれ量 H.Sakamoto
	plverr3 = ((LONG)xsae1 - (LONG)plvmag) / 0x100;
	if(hsaeunt && !tflunu){
		if( 0 != ((LONG)hsaeunt / 0x10000))	{
			plverrmm3 = ((LONG)xsae1 - (LONG)plvmag) / ((LONG)hsaeunt / 0x10000);
		}else {
			plverrmm3 = 0;
		}
	}else{
		plverrmm3 = 0;
	}
//↑TB3-0016 電子安全Lv4 FML中心位置からのずれ量 H.Sakamoto
	lwk0 = vabssign(plverr,0);
	lwk1 = vabssign(plverr3,0);	//TB3-0016 電子安全Lv4 FML中心位置からのずれ量 H.Sakamoto
//	prmcrzn = !(lwk0 <= (70 * ((LONG)hsaeunt / 0x10000) / 0x100))-1;
//	prmcrzn = !(lwk0 <= (70 * ((LONG)vsaeunt / 0x10000) / 0x100))-1;		//<012><11.06.10>KK UVF5 ﾎﾞｰﾙﾀｲﾌﾟｶﾞﾊﾞﾅ	//<V20>戸閉じマイクロ対応 2011.10.03 K.Sakai
//	prmcrzn = ( ~x40g  & (!(lwk0 <= (70 * ((LONG)vsaeunt / 0x10000) / 0x100))-1)) | x40g;	//C07 変更 2014.06.20 [D.Chen]
//	prmcrzn = ( ~x40g  & (!(lwk0 <= (70 * ((LONG)hsaeunt / 0x10000) / 0x100))-1)) | x40g;	//UCMP対応 安全ｺﾝ異常時ｶｯﾄ追加2014.07.22[D.Chen]
//	prmcrzn =(( ~x40g  & (!(lwk0 <= (55 * ((LONG)hsaeunt / 0x10000) / 0x100))-1)) | x40g)/* & ((!(h10sys(7) & BIT7)*-1) | ((!(h10sys(7) & BIT7)-1) & (!(tsafee & BIT31)*-1)))*/;
//↓<021> 香港UCMP対応
if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
	if(!vdxfms3){
		/*通常時*/
		prmcrzn =(( ~x40g  & (!(lwk0 <= (55 * ((LONG)hsaeunt / 0x10000) / 0x100))-1)) | x40g);
	}else{
		/*階高測定Phase3時*/
		prmcrzn = (!(lwk1 <= (50 * ((LONG)hsaeunt / 0x10000) / 0x100)) -1) | (x40g & ~v16n & v10);	//TB3-0016 H.Sakamoto
	}
}
else{
    prmcrzn =(( ~x40g  & (!(lwk0 <= (135 * ((LONG)hsaeunt / 0x10000) / 0x100))-1)) | x40g);
}
//↑<021> 香港UCMP対応
//追加↓ toughness 2014.08.09[D.Chen]
	prmcrzn1 = (v16p & v16up & (!(vx12pl & BIT31)-1) & (!(p900==1)-1) & (!(((LONG)pcpsh > 55)-1))) |
		   (v16p & v16dn & (!(vx11pl & BIT31)-1) & (!(p900==ipm300)-1) & (!(((LONG)pcpsh -(LONG)(ipm300pt[ipm300]) & 0xFFFFF) > 55)-1));    //2014.08.20 Matsukuma
	if(prmcrzn1 && !vt47sfg && !(*(wrbh + 2) & BIT31)){         //2014.08.20 Matsukuma
		vt47sfg = (ULONG)-1;
		wrbh[2]++;
	}
//追加↑ toughness 2014.08.09[D.Chen]
        if(!hincma || xincat){//<014> 荷物用対応 
//	if(pmczn && vflsae && psaelvok){
	if(pmczn && vflsae2 && psaelvok){			//<008><11.01.12>KK SAEﾏｲｸﾛ対策
		if(v16pw){
			if(!v16p){
//				if(lwk0 > h16p){
//				if((lwk0 / ((LONG)hsaeunt / 0x10000)) > (LONG)h16p){		//<00*><09.12.17>Iw LONGでの計算
//				if(lwk0 > ((LONG)h16p * ((LONG)hsaeunt / 0x10000) / 0x100)){	//<00*><09.12.21>Iw 演算誤り訂正
				if(lwk0 > ((LONG)h16p)){	//<00*><10.01.31>Iw h16pをSAE単位系とする
					*v16pww = cv16pww.cmt(prmcrzn);
                    if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
//  					tvmicro = ~prmcrzn;
    					trmicrov = ~prmcrzn;	//<018> 2017.08.29 [S.Kubo]
                    }//<021> 香港UCMP対応
//					v16pn = prmcrzn | v16n;					//<00*><09.12.21>Iw 戸閉じﾏｲｸﾛ対応	//<00*><10.02.12>Iw 移動
				}else{
					*v16pww = cv16pww.cmt(0);				//<00*><10.02.26>Iw 追加
                    if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
//  					tvmicro = ~prmcrzn;					//<00*><10.02.26>Iw 追加
    					trmicrov = ~prmcrzn;	//<018> 2017.08.29 [S.Kubo]
                    }//<021> 香港UCMP対応
				}
			}else{
//				if(!((lwk0 / ((LONG)hsaeunt / 0x10000)) <= ((LONG)h16p - ((LONG)hsaeunt / 0x10000 / 2 / 0x100)))){
//				if(lwk0 <= (((LONG)h16p * ((LONG)hsaeunt / 0x10000) / 0x100) - (((LONG)hsaeunt / 0x10000) / 0x100 / 2))){	//<00*><09.12.21>Iw 演算誤り訂正
//				if(!(lwk0 <= (((LONG)h16p * ((LONG)hsaeunt / 0x10000) / 0x100) - (((LONG)hsaeunt / 0x10000) / 0x100 / 2)))){	//<00*><09.12.22>Iw A/Bコン設定誤り
//				if(!(lwk0 <= ((LONG)h16p - (((LONG)hsaeunt / 0x10000) / 0x100 / 2)))){	//<00*><10.01.31>Iw h16pをSAE単位系とする
//				if(!(lwk0 <= ((LONG)h16p - (((LONG)vsaeunt / 0x10000) / 0x100 / 2)))){  //<012><11.06.10>KK UVF5 ﾎﾞｰﾙﾀｲﾌﾟｶﾞﾊﾞﾅ//C07 変更 2014.06.20 [D.Chen]
				if(!(lwk0 <= ((LONG)h16p - (((LONG)hsaeunt / 0x10000) / 0x100 / 2)))){ 
					*v16pww = cv16pww.cmt(prmcrzn);
                    if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
//  					tvmicro = ~prmcrzn;
    					trmicrov = ~prmcrzn;	//<018> 2017.08.29 [S.Kubo]
                    }//<021> 香港UCMP対応
//					v16pn = prmcrzn | v16n;					//<00*><09.12.21>Iw 戸閉じﾏｲｸﾛ対応	//<00*><10.02.12>Iw 移動
				}else{
					*v16pww = cv16pww.cmt(0);
                    if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
//  					tvmicro = ~prmcrzn;	//<00*><10.02.26>Iw 追加
    					trmicrov = ~prmcrzn;	//<018> 2017.08.29 [S.Kubo]
                    }//<021> 香港UCMP対応
//					v16pn = v16n;						//<00*><09.12.21>Iw 戸閉じﾏｲｸﾛ対応	//<00*><10.02.12>Iw 移動
				}
			}
		}
//		v16p = cv16pww.dmt();		//<00*><10.03.01>Iw 戸閉じﾏｲｸﾛ対応
//		v16p = v16pw & cv16pww.dmt();  //<035> <D098>
        ulwk0 = !((!hheavyload) || v16p || (!v60asr))-1;
		v16p = ulwk0 & v16pw & cv16pww.dmt();
//		v16pa = ~h16p & ~h16gain & ((lwk0 > (LONG)h16p) | (v16pa & (lwk0 > 5 * (LONG)hsaeunt / 0x10000 / 0x100)));	//<00*><09.12.03>Iw 訂正
//		v16pa = ~h16p & ~h16gain & ((lwk0 > (LONG)h16p) | (v16pa & (lwk0 > (5 * (LONG)hsaeunt / 0x10000 / 0x100))));	//<00*><09.12.17>Iw 訂正
//		v16pa = (!(h16p != 0) -1) & (!(h16gain != 0) -1) & (((lwk0 / ((LONG)hsaeunt / 0x10000)) > (LONG)h16p) | 	//<00*><09.12.21>Iw 演算誤り訂正
//		        (v16pa & ((lwk0 / ((LONG)hsaeunt / 0x10000)) > (5 * ((LONG)hsaeunt / 0x10000) / 0x100))));
//		v16pa = (!(h16p != 0) -1) & (!(h16gain != 0) -1) & ((!(lwk0 > ((LONG)h16p * ((LONG)hsaeunt / 0x10000) / 0x100))-1) | 
//		        (!(v16pa & (lwk0 > (5 * ((LONG)hsaeunt / 0x10000) / 0x100)))-1));
//		v16pa = (!(h16p != 0) -1) & (!(h16gain != 0) -1) & ((!(lwk0 > ((LONG)h16p))-1) | //<00*><10.01.31>Iw h16pをSAE単位系とする	//<012><11.06.22>Iw GB規格対応
//		        (!(v16pa & (lwk0 > (5 * ((LONG)hsaeunt / 0x10000) / 0x100)))-1));
//		v16pa = v16p | (v16pa & ~v10);		//<019><12.01.24>KK ﾏｲｸﾛ時#5/#5r:OFF(B-SE対応) 
//SAE1 ↓ SAEﾏｲｸﾛ機能をｶｯﾄ(70mmﾚﾍﾞﾙずれで起動)
		v16pa = (!(h16p != 0) -1) & (!(h16gain != 0) -1) & ((!(lwk0 > ((LONG)h16p))-1) |
//		        (!(v16pa & (lwk0 > (5 * ((LONG)vsaeunt / 0x10000) / 0x100)))-1));	//C07 変更 2014.06.20 [D.Chen]
		        (!(v16pa & (lwk0 > (5 * ((LONG)hsaeunt / 0x10000) / 0x100)))-1));
//		v16pa = (!(h16p != 0) -1) & (!(h16gain != 0) -1) & ((!(lwk0 > ((70 * (vsaeunt / 0x10000) / 0x100)))-1) |
//		        (!(v16pa & (lwk0 > (5 * ((LONG)vsaeunt / 0x10000) / 0x100)))-1));
//SAE1 ↑ SAEﾏｲｸﾛ機能をｶｯﾄここまで(70mmﾚﾍﾞﾙずれで起動)
		if(!(plverr > 0)){
			v16up = 0xFFFFFFFF;
			v16dn = 0;
		}else{
			v16up = 0;
			v16dn = 0xFFFFFFFF;
		}
	}
	else{					//<008><11.01.12>KK SAEﾏｲｸﾛ対策
		v16p = 0;
		v16pa = 0;
		v16up = 0;
		v16dn = 0;
	}
	//<00*><10.02.12>Iw v16pn条件訂正ここから
//	ulwk1 = (v16up | v16dn) & (!(lwk0 > ((LONG)h16p)) -1) & ~ctmicro.dmt() & prmcrzn;	//<00*><10.02.16>Iw SAEﾏｲｸﾛ戸閉じ対応
//	ulwk1 = v16pnw & (v16up | v16dn) & (!(lwk0 > ((LONG)h16p)) -1) & ~ctmicro.dmt() & prmcrzn;	//追加 14.08.16 [T.Matsukuma]
	ulwk1 = v16pnw & (v16up | v16dn) & ((~v16p & (!(lwk0 > ((LONG)h16p)) -1)) | (v16p & (!(lwk0 > ((LONG)h16p - (((LONG)hsaeunt / 0x10000) / 0x100 / 2)))-1))) & ~ctmicro.dmt() & prmcrzn;
	v16pn = ulwk1 | v16n;
	//<00*><10.02.12>Iw v16pn条件訂正ここまで
	if(v16){
		lwk5 = vabssign(plverr,0);
		lwk1 = lwk5 * (LONG)h16gain * 0x40;	//<00*><09.12.22>Iw 平方根計算追加
		ulwk0 = r2roots((ULONG)lwk1);
//		if(x40g){		//<00*><09.12.22>Iw 戸閉じﾏｲｸﾛ対応
//			lwk5 = 0;
//		}
//		if((lwk5 * h16gain * 0x20) >= h16splm){			//<00*><09.12.22>Iw LONGに統一
		if((LONG)ulwk0 >= (LONG)h16splm){
			vmccmd = (LONG)h16splm;
		}else{
//			if(lwk5 >= (h16p * 4 / 13)){			//<00*><09.12.22>Iw SAE型に変更
//			if(lwk5 >= (((LONG)h16p * ((LONG)hsaeunt / 0x10000) / 0x100) * 4 / 13)){
			if(lwk5 >= (((LONG)h16p) * 4 / 13)){		//<00*><10.01.31>Iw h16pをSAE単位系とする
//				vmccmd = lwk5 * (LONG)h16gain * 0x20;
				vmccmd = (LONG)ulwk0;			//<00*><09.12.22>Iw 平方根計算追加
			}else{
				vmccmd = 0;
			}
		}
//		v16cmd += (LONG)hmcnst * (vmccmd - v16cmd) * 0x20;	//<00*><09.12.22>Iw 演算式訂正
		v16cmd += (LONG)hmcnst * (vmccmd - v16cmd) / 0x10000;
//↓<035> <D098>
        vmcrzns = ((!(lwk5 < ((LONG)h16p))-1) & BIT31) | (vmcrzns>>1);
        if((vmcrzns & 0xE0000000) == 0xE0000000){
            vmcrznsx = 0xFFFFFFFF;
        }
        ulwk0 = !(hheavyload && !plv0cr && (v16cmd > (LONG)0x30))-1;
        ulwk1 = !(vmcrznsx && ((vmcrzns & 0xE0000000) == 0x00000000))-1;
        ulwk2 = !(((plverr < (LONG)0) && (plverrz1 >= (LONG)0)) || ((plverr >= (LONG)0) && (plverrz1 < (LONG)0)))-1;
        plv0cr = ulwk0 & (ulwk1 | ulwk2);
        plverrz1 = plverr;
//↑<035> <D098>
//		ulwk0 = ((!(vmccmd == 0)-1) & (!(v16cmd <= 0x30)-1)) | ~cv16rt.dmt();	//<00*><10.02.12>Iw 条件訂正
		ulwk0 = ((!(vmccmd == 0)-1) & (!(v16cmd <= 0x30)-1)) | cv16rt.tmt();
		*v16rt = cv16rt.cmt(ulwk0);
//		if(cv16rt.dmt()){  //<035> <D098>
		if(cv16rt.dmt() || plv0cr){
//			if(!x40g){
//				v15b = 0;
//			}
			v15b = 0;	//<00*><09.12.22>Iw 戸閉じﾏｲｸﾛ対応
			v16 = 0;
//			vabrans = 0;	//<012><11.06.22>Iw 誤記訂正
			vabrans = 0xFFFFFFFF;
			*v16rt = cv16rt.cmt((ULONG)-1);
			v16nh = 0;
            if(plv0cr){  //<035> <D098>
                v16n = 0;
                v16pw = 0;
                vib60supq = 0;
            }
		}
	}
	else{
		*v16rt = cv16rt.cmt(0);
		vmccmd = 0;
		v16cmd = 0;
        if(!v60asr){
            plv0cr = 0;    //<035> <D098>
            vmcrzns = 0;   //<035> <D098>
            vmcrznsx = 0;  //<035> <D098>
        }
	}
        }//<014> 荷物用対応 
#if (3 <= V_UCMP_MODE) //UA-23以降  //<035> <D064>
	set_imask(13);
	if((LONG)p900psh < (LONG)0x0){														//ﾃﾞｼﾞﾌﾛﾏｲﾅｽ条件追加
//		ulwk1 = (v16n & (!(vxsped > 14) -1)) | (~v10 & ctmicro2.dmt());			// UCMPﾏｲｸﾛ対応	//<018> 2017.08.29 [S.Kubo]	速度監視装置15m/min追加  //<020> 2018.01.04 [Y.Saito]
		ulwk1 = ((v16n | (htst_modeh & (!(vmicrotmd == 0xA55A5AA5) -1))) & (!(vxsped > 14) -1)) | (~v10 & ctmicro2.dmt());			// UCMPﾏｲｸﾛ対応
	}
	else{
//		ulwk1 = (v16n & (!(vxsped > 14) -1)) | (~v10 & ctmicro2.dmt());			// UCMPﾏｲｸﾛ対応	//<018> 2017.08.29 [S.Kubo]	速度監視装置15m/min追加  //<020> 2018.01.04 [Y.Saito]
		ulwk1 = ((v16n | (htst_modeh & (!(vmicrotmd == 0xA55A5AA5) -1))) & (!(vxsped > 14) -1)) | (~v10 & ctmicro2.dmt());			// UCMPﾏｲｸﾛ対応
	}
	set_imask(0);
	if(!(hucmptmd == 0xFFFFFFFF) || !(xucmptb == 0xFFFFFFFF) || !(xvucmptb == 0x5A5AA5A5) || !(xucmpta == 0xA5A55A5A) || !(xvucmpta == 0x5A5AA5A5)){//<021> 香港UCMP対応
		*tmicro2 = ctmicro2.cmt(rmsb_yesnos(ulwk1));				//UCMPﾏｲｸﾛ対応
	}//<021> 香港UCMP対応
	tvmicro = ctmicro2.dmt() | trmicrov;			//ﾏｲｸﾛ建築基準法対応
	tvmicro2 = tvmicro & ~x40g & ~visup3t & z16;				//<UCMP> 2013.11.27 [N.Takayama]
#endif				//<035> <D064>
}
else{	//<019><12.01.23>KK SAEﾏｲｸﾛ瞬停対応
	if(h10sys(2) & BIT4){
		pmczn = 0;
		plverrw = 0;
		plverr = 0;
		plverrmm = 0;
		vlverr = 0;
		psaelvok = 0;
//		tvmicro = 0;		//<018> 2017.08.29 [S.Kubo]
		trmicrov = 0;
		v16pa = 0;
                if(!hincma || xincat){//<014> 荷物用対応 
		    v16up = 0;
		    v16dn = 0;
		    *v16pww = cv16pww.cmt(0);
		    v16p = 0;
		    prmcrzn = 0;
                }//<014> 荷物用対応 
		v16pn = 0;
		vmccmd = 0;
		v16cmd = 0;
		*v16rt = cv16rt.cmt(0);
	}
}

//↓<035> <D038>UCMP動作遅れ時間測定
    uycnt++;
    //<000> [CHG] st---
//	z10ty			= ((!(*(ropbfp + 0) & 0x00000800)  -1) & BIT31) | (z10ty / 2);
//	x10ty			= ((!(*(ripbfp + 0) & 0x00000008) *-1) & BIT31) | (x10ty / 2);
//	x10tcy			= ((!(*(ripbfp + 1) & 0x00040000)  -1) & BIT31) | (x10tcy / 2);
//	xenbcs1y		= ((!(*(ripbfp + 0) & 0x20000000) *-1) & BIT31) | (xenbcs1y / 2);
//	xenbcs2y		= ((!(*(ripbfp + 0) & 0x40000000) *-1) & BIT31) | (xenbcs2y / 2);
	z10ty			= ((!(*(ropbfp + 0) & E_LBIT11 )  -1) & BIT31) | (z10ty / 2);
	x10ty			= ((!(*(ripbfp + 0) & E_LBIT03 ) *-1) & BIT31) | (x10ty / 2);
	x10tcy			= ((!(*(ripbfp + 1) & E_LBIT18 )  -1) & BIT31) | (x10tcy / 2);
	xenbcs1y		= ((!(*(ripbfp + 0) & E_LBIT29 ) *-1) & BIT31) | (xenbcs1y / 2);
	xenbcs2y		= ((!(*(ripbfp + 0) & E_LBIT30 ) *-1) & BIT31) | (xenbcs2y / 2);
    //<000> [CHG] ed---
//↓<25.04.16>M.Miyamae 動作時間格納順変更
//    p=&z10ty;
//    q=&z10tyt;
    p=&xenbcs2y;
    q=&xenbcs2yt;
//↑<25.04.16>M.Miyamae 動作時間格納順変更
    for(a=0;a<5;a++){
        if(((*(p+a)) & 0xC0000000)==0x40000000){
            *(q+a) = uycnt;
        }
    }

    ulwk4 = 100; //1000ms上限

    if((x10ty & 0xC0000000)==0x40000000){
		ulwk0 = x10tyt - z10tyt;
        ulwk1 = x10tyt - x10tcyt;
        if(ulwk4 < ulwk0){		//上限超えの場合はｸﾘｱ
            ulwk0 = 0;
        }
        if(ulwk4 < ulwk1){		//上限超えの場合はｸﾘｱ
            ulwk1 = 0;
        }
        if(ulwk0 < ulwk1){
            ulwk0 = ulwk1;
        }
        x10tyc = ulwk0;					//T2:Sコンタクタ動作遅れ
	}
	if(vutstf && vutstf1){	//制動距離確認用試験ﾓｰﾄﾞ時のみ判定
		x10tycms = x10tyc * 10;
		xctcms = x10tycms;
		if(h10tct != 0x00000000){
			if(x10tyc > h10tct){
				tucmpcber |= BIT1;
			}
		}
	}

    if(!(xenbcs1y | xenbcs2y)){
        ulwk1 = xenbcs1yt - z10tyt;
        ulwk2 = xenbcs2yt - z10tyt;
        if(ulwk4 < ulwk1){		//上限超えの場合はｸﾘｱ
            ulwk1 = 0;
        }
        if(ulwk4 < ulwk2){		//上限超えの場合はｸﾘｱ
            ulwk2 = 0;
        }
		if(ulwk1 < ulwk2){
            ulwk1 = ulwk2;
        }
		ulwk3 = ulwk1;			//ulwk3に格納

		ulwk1 = xenbcs1yt - x10tcyt;
		ulwk2 = xenbcs2yt - x10tcyt;
        if(ulwk4 < ulwk1){		//上限超えの場合はｸﾘｱ
            ulwk1 = 0;
        }
        if(ulwk4 < ulwk2){		//上限超えの場合はｸﾘｱ
            ulwk2 = 0;
        }
		if(ulwk1 < ulwk2){
            ulwk1 = ulwk2;
        }
		if(ulwk3 < ulwk1){
			ulwk3 = ulwk1;			//最大値更新の場合、ulwk3に格納
		}
		t2t3yc = ulwk3;		//T2+T3

		if(vutstf && vutstf1){	//制動距離確認用試験ﾓｰﾄﾞ時のみ判定
			if(x10tyc >= t2t3yc){    //x10t入力よりbcs入力の方が早い場合
				xenbcsyc = 1;
			}
			else{
				xenbcsyc = t2t3yc - x10tyc;		//T3:ブレーキ動作遅れ
			}
	    	xenbcsycms = xenbcsyc * 10;
			if(henbcsct != 0x00000000){
				if(xenbcsyc > henbcsct){
					tucmpcber |= BIT0;
				}
			}
		}
	}

    if((tucmpcber & 0x0000003F) != 0x00000000){
    		tucmpcber |= BIT31;
    }
//↑<035> <D038>UCMP動作遅れ時間測定
return (ULONG)-1;
}
