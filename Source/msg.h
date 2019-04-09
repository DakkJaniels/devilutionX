//HEADER_GOES_HERE
#ifndef __MSG_H__
#define __MSG_H__

extern BOOL deltaload;
extern BYTE gbBufferMsgs;
extern int pkt_counter;

void msg_send_drop_pkt(int pnum, int reason);
void msg_send_packet(int pnum, const void *packet, DWORD dwSize);
TMegaPkt *msg_get_next_packet();
BOOL msg_wait_resync();
void msg_free_packets();
int msg_wait_for_turns();
void msg_process_net_packets();
void msg_pre_packet();
void DeltaExportData(int pnum);
BYTE *DeltaExportItem(BYTE *dst, TCmdPItem *src);
BYTE *DeltaExportObject(BYTE *dst, DObjectStr *src);
BYTE *DeltaExportMonster(BYTE *dst, DMonsterStr *src);
BYTE *DeltaExportJunk(BYTE *dst);
int msg_comp_level(BYTE *buffer, BYTE *end);
void delta_init();
void delta_kill_monster(int mi, BYTE x, BYTE y, BYTE bLevel);
void delta_monster_hp(int mi, int hp, BYTE bLevel);
void delta_sync_monster(const TSyncMonster *pSync, BYTE bLevel);
void delta_sync_golem(TCmdGolem *pG, int pnum, BYTE bLevel);
void delta_leave_sync(BYTE bLevel);
BOOL delta_portal_inited(int i);
BOOL delta_quest_inited(int i);
void DeltaAddItem(int ii);
void DeltaSaveLevel();
void DeltaLoadLevel();
void NetSendCmd(BOOL bHiPri, BYTE bCmd);
void NetSendCmdGolem(BYTE mx, BYTE my, BYTE dir, BYTE menemy, int hp, BYTE cl);
void NetSendCmdLoc(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void NetSendCmdLocParam1(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1);
void NetSendCmdLocParam2(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2);
void NetSendCmdLocParam3(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y, WORD wParam1, WORD wParam2, WORD wParam3);
void NetSendCmdParam1(BOOL bHiPri, BYTE bCmd, WORD wParam1);
void NetSendCmdParam2(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2);
void NetSendCmdParam3(BOOL bHiPri, BYTE bCmd, WORD wParam1, WORD wParam2, WORD wParam3);
void NetSendCmdQuest(BOOL bHiPri, BYTE q);
void NetSendCmdGItem(BOOL bHiPri, BYTE bCmd, BYTE mast, BYTE pnum, BYTE ii);
void NetSendCmdGItem2(BOOL usonly, BYTE bCmd, BYTE mast, BYTE pnum, TCmdGItem *p);
BOOL NetSendCmdReq2(BYTE bCmd, BYTE mast, BYTE pnum, TCmdGItem *p);
void NetSendCmdExtra(TCmdGItem *p);
void NetSendCmdPItem(BOOL bHiPri, BYTE bCmd, BYTE x, BYTE y);
void NetSendCmdChItem(BOOL bHiPri, BYTE bLoc);
void NetSendCmdDelItem(BOOL bHiPri, BYTE bLoc);
void NetSendCmdDItem(BOOL bHiPri, int ii);
void NetSendCmdDamage(BOOL bHiPri, BYTE bPlr, DWORD dwDam);
void NetSendCmdString(int pmask, const char *pszStr);
void RemovePlrPortal(int pnum);
int ParseCmd(int pnum, TCmd *pCmd);
int On_DLEVEL(int pnum, TCmdPlrInfoHdr *pCmd);
void DeltaImportData(BYTE cmd, DWORD recv_offset);
BYTE *DeltaImportItem(BYTE *src, TCmdPItem *dst);
BYTE *DeltaImportObject(BYTE *src, DObjectStr *dst);
BYTE *DeltaImportMonster(BYTE *src, DMonsterStr *dst);
void DeltaImportJunk(BYTE *src);
int On_SYNCDATA(void *packet, int pnum);
int On_WALKXY(TCmdLoc *pCmd, int pnum);
int On_ADDSTR(TCmdParam1 *pCmd, int pnum);
int On_ADDMAG(TCmdParam1 *pCmd, int pnum);
int On_ADDDEX(TCmdParam1 *pCmd, int pnum);
int On_ADDVIT(TCmdParam1 *pCmd, int pnum);
int On_SBSPELL(TCmdParam1 *pCmd, int pnum);
void __cdecl msg_errorf(const char *pszFmt, ...);
int On_GOTOGETITEM(TCmdLocParam1 *pCmd, int pnum);
int On_REQUESTGITEM(TCmdGItem *pCmd, int pnum);
BOOL i_own_level(int nReqLevel);
int On_GETITEM(TCmdGItem *pCmd, int pnum);
BOOL delta_get_item(TCmdGItem *pI, BYTE bLevel);
int On_GOTOAGETITEM(TCmdLocParam1 *pCmd, int pnum);
int On_REQUESTAGITEM(TCmdGItem *pCmd, int pnum);
int On_AGETITEM(TCmdGItem *pCmd, int pnum);
int On_ITEMEXTRA(TCmdGItem *pCmd, int pnum);
int On_PUTITEM(TCmdPItem *pCmd, int pnum);
void delta_put_item(TCmdPItem *pI, int x, int y, BYTE bLevel);
void check_update_plr(int pnum);
int On_SYNCPUTITEM(TCmdPItem *pCmd, int pnum);
int On_RESPAWNITEM(TCmdPItem *pCmd, int pnum);
int On_ATTACKXY(TCmdLoc *pCmd, int pnum);
int On_SATTACKXY(TCmdLoc *pCmd, int pnum);
int On_RATTACKXY(TCmdLoc *pCmd, int pnum);
int On_SPELLXYD(TCmdLocParam3 *pCmd, int pnum);
int On_SPELLXY(TCmdLocParam2 *pCmd, int pnum);
int On_TSPELLXY(TCmdLocParam2 *pCmd, int pnum);
int On_OPOBJXY(TCmdLocParam1 *pCmd, int pnum);
int On_DISARMXY(TCmdLocParam1 *pCmd, int pnum);
int On_OPOBJT(TCmdParam1 *pCmd, int pnum);
int On_ATTACKID(TCmdParam1 *pCmd, int pnum);
int On_ATTACKPID(TCmdParam1 *pCmd, int pnum);
int On_RATTACKID(TCmdParam1 *pCmd, int pnum);
int On_RATTACKPID(TCmdParam1 *pCmd, int pnum);
int On_SPELLID(TCmdParam3 *pCmd, int pnum);
int On_SPELLPID(TCmdParam3 *pCmd, int pnum);
int On_TSPELLID(TCmdParam3 *pCmd, int pnum);
int On_TSPELLPID(TCmdParam3 *pCmd, int pnum);
int On_KNOCKBACK(TCmdParam1 *pCmd, int pnum);
int On_RESURRECT(TCmdParam1 *pCmd, int pnum);
int On_HEALOTHER(TCmdParam1 *pCmd, int pnum);
int On_TALKXY(TCmdLocParam1 *pCmd, int pnum);
int On_NEWLVL(TCmdParam2 *pCmd, int pnum);
int On_WARP(TCmdParam1 *pCmd, int pnum);
int On_MONSTDEATH(TCmdLocParam1 *pCmd, int pnum);
int On_KILLGOLEM(TCmdLocParam1 *pCmd, int pnum);
int On_AWAKEGOLEM(TCmdGolem *pCmd, int pnum);
int On_MONSTDAMAGE(TCmdParam2 *pCmd, int pnum);
int On_PLRDEAD(TCmdParam1 *pCmd, int pnum);
int On_PLRDAMAGE(TCmdDamage *pCmd, int pnum);
int On_OPENDOOR(TCmdParam1 *pCmd, int pnum);
void delta_sync_object(int oi, BYTE bCmd, BYTE bLevel);
int On_CLOSEDOOR(TCmdParam1 *pCmd, int pnum);
int On_OPERATEOBJ(TCmdParam1 *pCmd, int pnum);
int On_PLROPOBJ(TCmdParam2 *pCmd, int pnum);
int On_BREAKOBJ(TCmdParam2 *pCmd, int pnum);
int On_CHANGEPLRITEMS(TCmdChItem *pCmd, int pnum);
int On_DELPLRITEMS(TCmdDelItem *pCmd, int pnum);
int On_PLRLEVEL(TCmdParam1 *pCmd, int pnum);
int On_DROPITEM(TCmdPItem *pCmd, int pnum);
int On_SEND_PLRINFO(TCmdPlrInfoHdr *pCmd, int pnum);
int On_ACK_PLRINFO(TCmdPlrInfoHdr *pCmd, int pnum);
int On_PLAYER_JOINLEVEL(TCmdLocParam1 *pCmd, int pnum);
int On_ACTIVATEPORTAL(TCmdLocParam3 *pCmd, int pnum);
void delta_open_portal(int pnum, BYTE x, BYTE y, BYTE bLevel, BYTE bLType, BYTE bSetLvl);
int On_DEACTIVATEPORTAL(TCmd *pCmd, int pnum);
int On_RETOWN(TCmd *pCmd, int pnum);
int On_SETSTR(TCmdParam1 *pCmd, int pnum);
int On_SETDEX(TCmdParam1 *pCmd, int pnum);
int On_SETMAG(TCmdParam1 *pCmd, int pnum);
int On_SETVIT(TCmdParam1 *pCmd, int pnum);
int On_STRING(TCmdString *pCmd, int pnum);
int On_STRING2(int pnum, TCmdString *pCmd);
int On_SYNCQUEST(TCmdQuest *pCmd, int pnum);
int On_ENDSHIELD(TCmd *pCmd, int pnum);
int On_CHEAT_EXPERIENCE(TCmd *pCmd, int pnum);
int On_CHEAT_SPELL_LEVEL(TCmd *pCmd, int pnum);
int On_DEBUG(TCmd *pCmd, int pnum);
int On_NOVA(TCmdLoc *pCmd, int pnum);
int On_SETSHIELD(TCmd *pCmd, int pnum);
int On_REMSHIELD(TCmd *pCmd, int pnum);

#endif /* __MSG_H__ */
