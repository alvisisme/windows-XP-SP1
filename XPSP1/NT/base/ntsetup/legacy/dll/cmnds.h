/* File: cmnds.h */
/**************************************************************************/
/*  Install: Commands Header File.
/**************************************************************************/


#define szNull ((SZ)NULL)

/*  Returns the number of lines in the given section
*/
#define CLinesFromInfSection(szSect)    CKeysFromInfSection((szSect), fTrue)



/*  CoMmand Options
*/
typedef BYTE CMO;
#define cmoVital     1
#define cmoOverwrite 2
#define cmoAppend    4
#define cmoPrepend   8
#define cmoNone   0x00
#define cmoAll    0xFF

  /* filecm.c */
extern BOOL  APIENTRY FCopyFilesInCopyList(HANDLE);

#ifdef UNUSED
extern BOOL  APIENTRY FBackupSectionFiles(SZ, SZ);
extern BOOL  APIENTRY FBackupSectionKeyFile(SZ, SZ, SZ);
extern BOOL  APIENTRY FBackupNthSectionFile(SZ, USHORT, SZ);
extern BOOL  APIENTRY FRemoveSectionFiles(SZ, SZ);
extern BOOL  APIENTRY FRemoveSectionKeyFile(SZ, SZ, SZ);
extern BOOL  APIENTRY FRemoveNthSectionFile(SZ, USHORT, SZ);
#endif // UNUSED


extern BOOL  APIENTRY FCreateDir(SZ, CMO);
extern BOOL  APIENTRY FRemoveDir(SZ, CMO);

/* inicm.c */
extern BOOL  APIENTRY FCreateIniSection(SZ, SZ, CMO);
extern BOOL  APIENTRY FReplaceIniSection(SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FRemoveIniSection(SZ, SZ, CMO);
extern BOOL  APIENTRY FCreateIniKeyNoValue(SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FCreateIniKeyValue(SZ, SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FReplaceIniKeyValue(SZ, SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FAppendIniKeyValue(SZ, SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FRemoveIniKey(SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FCreateSysIniKeyValue(SZ, SZ, SZ, SZ, CMO);
extern BOOL  APIENTRY FAddDos5Help(SZ, SZ, CMO);


/* progcm.c */
extern BOOL  APIENTRY FCreateProgManGroup(SZ, SZ, CMO, BOOL);
extern BOOL  APIENTRY FRemoveProgManGroup(SZ, CMO, BOOL);
extern BOOL  APIENTRY FShowProgManGroup(SZ, SZ, CMO, BOOL);
extern BOOL  APIENTRY FCreateProgManItem(SZ, SZ, SZ, SZ, INT, CMO, BOOL);
extern BOOL  APIENTRY FRemoveProgManItem(SZ, SZ, CMO, BOOL);
// extern BOOL  APIENTRY EndProgmanDde(VOID);

/* misccm.c */

extern BOOL  APIENTRY FSetEnvVariableValue(SZ, SZ, SZ, CMO);
#ifdef UNUSED
extern BOOL  APIENTRY FAddMsgToSystemHelpFile(SZ, SZ, CMO);
#endif /* UNUSED */
extern BOOL  APIENTRY FStampFile(SZ, SZ, SZ, WORD, WORD, SZ, WORD);
extern BOOL  APIENTRY FStampResource(SZ, SZ, SZ, WORD, WORD, SZ, CB);  // 1632

/* extprog.c */

       BOOL FLoadLibrary(SZ DiskName,SZ File,SZ INFVar);
       BOOL FFreeLibrary(SZ INFVar);
       BOOL FLibraryProcedure(SZ INFVar,SZ HandleVar,SZ EntryPoint,RGSZ Args);
       BOOL FRunProgram(SZ,SZ,SZ,SZ,RGSZ);
       BOOL FStartDetachedProcess(SZ,SZ,SZ,SZ,RGSZ);
       BOOL FInvokeApplet(SZ);

/* event.c */
       BOOL FWaitForEvent(IN LPSTR InfVar,IN LPSTR EventName,IN DWORD Timeout);
       BOOL FSignalEvent(IN LPSTR InfVar,IN LPSTR EventName);
       BOOL FSleep(IN DWORD Milliseconds);

/* registry.c */

#define REGLASTERROR    "RegLastError"

       BOOL FCreateRegKey( SZ szHandle, SZ szKeyName, UINT TitleIndex, SZ szClass,
                           SZ Security, UINT Access, UINT Options, SZ szNewHandle,
                           CMO cmo );
       BOOL FOpenRegKey( SZ szHandle, SZ szMachineName, SZ szKeyName, UINT Access, SZ szNewHandle, CMO cmo );
       BOOL FFlushRegKey( SZ szHandle, CMO cmo );
       BOOL FCloseRegKey( SZ szHandle, CMO cmo );
       BOOL FDeleteRegKey( SZ szHandle, SZ szKeyName, CMO cmo );
       BOOL FDeleteRegTree( SZ szHandle, SZ szKeyName, CMO cmo );
       BOOL FEnumRegKey( SZ szHandle, SZ szInfVar, CMO cmo );
       BOOL FSetRegValue( SZ szHandle, SZ szValueName, UINT TitleIndex, UINT ValueType,
                          SZ szValueData, CMO cmo );
       BOOL FGetRegValue( SZ szHandle, SZ szValueName, SZ szInfVar, CMO cmo );
       BOOL FDeleteRegValue( SZ szHandle, SZ szValueName, CMO cmo );
       BOOL FEnumRegValue( SZ szHandle, SZ szInfVar, CMO cmo );


/* bootini.c */

       BOOL FChangeBootIniTimeout(INT Timeout);


/* restore.c */

//       BOOL SaveRegistryHives();
//       BOOL GenerateRepairDisk(PCHAR Drive);
//       BOOL CopyFilesToRepairDisk(PCHAR Drive);
//       BOOL SaveVdmFiles();
