  function targMap = targDataMap(),

  ;%***********************
  ;% Create Parameter Map *
  ;%***********************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 4;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc paramMap
    ;%
    paramMap.nSections           = nTotSects;
    paramMap.sectIdxOffset       = sectIdxOffset;
      paramMap.sections(nTotSects) = dumSection; %prealloc
    paramMap.nTotData            = -1;
    
    ;%
    ;% Auto data (helikopter04day4OptMedFeed_P)
    ;%
      section.nData     = 47;
      section.data(47)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04day4OptMedFeed_P.Constant1_Value
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04day4OptMedFeed_P.VandringLavpass_A
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04day4OptMedFeed_P.VandringLavpass_C
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04day4OptMedFeed_P.KalibrerVandring_Gain
	  section.data(14).logicalSrcIdx = 15;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04day4OptMedFeed_P.VandringDeriv_A
	  section.data(15).logicalSrcIdx = 16;
	  section.data(15).dtTransOffset = 14;
	
	  ;% helikopter04day4OptMedFeed_P.VandringDeriv_C
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
	  ;% helikopter04day4OptMedFeed_P.VandringDeriv_D
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 16;
	
	  ;% helikopter04day4OptMedFeed_P.KalibrerPitch_Gain
	  section.data(18).logicalSrcIdx = 20;
	  section.data(18).dtTransOffset = 17;
	
	  ;% helikopter04day4OptMedFeed_P.TransferFcn4_A
	  section.data(19).logicalSrcIdx = 21;
	  section.data(19).dtTransOffset = 18;
	
	  ;% helikopter04day4OptMedFeed_P.TransferFcn4_C
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 19;
	
	  ;% helikopter04day4OptMedFeed_P.TransferFcn4_D
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 20;
	
	  ;% helikopter04day4OptMedFeed_P.KalibrerElev_Gain
	  section.data(22).logicalSrcIdx = 25;
	  section.data(22).dtTransOffset = 21;
	
	  ;% helikopter04day4OptMedFeed_P.Constant_Value
	  section.data(23).logicalSrcIdx = 26;
	  section.data(23).dtTransOffset = 22;
	
	  ;% helikopter04day4OptMedFeed_P.TransferFcn5_A
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 23;
	
	  ;% helikopter04day4OptMedFeed_P.TransferFcn5_C
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 24;
	
	  ;% helikopter04day4OptMedFeed_P.TransferFcn5_D
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 25;
	
	  ;% helikopter04day4OptMedFeed_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 31;
	  section.data(27).dtTransOffset = 26;
	
	  ;% helikopter04day4OptMedFeed_P.Gain1_Gain
	  section.data(28).logicalSrcIdx = 32;
	  section.data(28).dtTransOffset = 62;
	
	  ;% helikopter04day4OptMedFeed_P.Integrator_IC
	  section.data(29).logicalSrcIdx = 33;
	  section.data(29).dtTransOffset = 74;
	
	  ;% helikopter04day4OptMedFeed_P.Integrator_UpperSat
	  section.data(30).logicalSrcIdx = 34;
	  section.data(30).dtTransOffset = 75;
	
	  ;% helikopter04day4OptMedFeed_P.Integrator_LowerSat
	  section.data(31).logicalSrcIdx = 35;
	  section.data(31).dtTransOffset = 76;
	
	  ;% helikopter04day4OptMedFeed_P.K_ed_Gain
	  section.data(32).logicalSrcIdx = 36;
	  section.data(32).dtTransOffset = 77;
	
	  ;% helikopter04day4OptMedFeed_P.K_ei_Gain
	  section.data(33).logicalSrcIdx = 37;
	  section.data(33).dtTransOffset = 78;
	
	  ;% helikopter04day4OptMedFeed_P.K_ep_Gain
	  section.data(34).logicalSrcIdx = 38;
	  section.data(34).dtTransOffset = 79;
	
	  ;% helikopter04day4OptMedFeed_P.Saturation_UpperSat
	  section.data(35).logicalSrcIdx = 39;
	  section.data(35).dtTransOffset = 80;
	
	  ;% helikopter04day4OptMedFeed_P.Saturation_LowerSat
	  section.data(36).logicalSrcIdx = 40;
	  section.data(36).dtTransOffset = 81;
	
	  ;% helikopter04day4OptMedFeed_P.Saturation_UpperSat_p
	  section.data(37).logicalSrcIdx = 41;
	  section.data(37).dtTransOffset = 82;
	
	  ;% helikopter04day4OptMedFeed_P.Saturation_LowerSat_b
	  section.data(38).logicalSrcIdx = 42;
	  section.data(38).dtTransOffset = 83;
	
	  ;% helikopter04day4OptMedFeed_P.K_pp_Gain
	  section.data(39).logicalSrcIdx = 43;
	  section.data(39).dtTransOffset = 84;
	
	  ;% helikopter04day4OptMedFeed_P.K_pd_Gain
	  section.data(40).logicalSrcIdx = 44;
	  section.data(40).dtTransOffset = 85;
	
	  ;% helikopter04day4OptMedFeed_P.Gain2_Gain
	  section.data(41).logicalSrcIdx = 45;
	  section.data(41).dtTransOffset = 86;
	
	  ;% helikopter04day4OptMedFeed_P.SatB_UpperSat
	  section.data(42).logicalSrcIdx = 46;
	  section.data(42).dtTransOffset = 87;
	
	  ;% helikopter04day4OptMedFeed_P.SatB_LowerSat
	  section.data(43).logicalSrcIdx = 47;
	  section.data(43).dtTransOffset = 88;
	
	  ;% helikopter04day4OptMedFeed_P.Gain1_Gain_e
	  section.data(44).logicalSrcIdx = 48;
	  section.data(44).dtTransOffset = 89;
	
	  ;% helikopter04day4OptMedFeed_P.Sat_UpperSat
	  section.data(45).logicalSrcIdx = 49;
	  section.data(45).dtTransOffset = 90;
	
	  ;% helikopter04day4OptMedFeed_P.Sat_LowerSat
	  section.data(46).logicalSrcIdx = 50;
	  section.data(46).dtTransOffset = 91;
	
	  ;% helikopter04day4OptMedFeed_P.Constant_Value_p
	  section.data(47).logicalSrcIdx = 51;
	  section.data(47).dtTransOffset = 92;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 52;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_CKModes
	  section.data(2).logicalSrcIdx = 53;
	  section.data(2).dtTransOffset = 6;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 54;
	  section.data(3).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 55;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 56;
	  section.data(2).dtTransOffset = 16;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_EIQuadrature
	  section.data(3).logicalSrcIdx = 57;
	  section.data(3).dtTransOffset = 20;
	
	  ;% helikopter04day4OptMedFeed_P.HILReadEncoder_Channels
	  section.data(4).logicalSrcIdx = 58;
	  section.data(4).dtTransOffset = 21;
	
	  ;% helikopter04day4OptMedFeed_P.HILWriteAnalog_Channels
	  section.data(5).logicalSrcIdx = 59;
	  section.data(5).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 60;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 61;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 62;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 63;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 64;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 65;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 66;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 67;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 68;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 69;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 70;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 71;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 72;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 73;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 74;
	  section.data(15).dtTransOffset = 14;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 75;
	  section.data(16).dtTransOffset = 15;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 76;
	  section.data(17).dtTransOffset = 16;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 77;
	  section.data(18).dtTransOffset = 17;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 78;
	  section.data(19).dtTransOffset = 18;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 79;
	  section.data(20).dtTransOffset = 19;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 80;
	  section.data(21).dtTransOffset = 20;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 81;
	  section.data(22).dtTransOffset = 21;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 82;
	  section.data(23).dtTransOffset = 22;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 83;
	  section.data(24).dtTransOffset = 23;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 84;
	  section.data(25).dtTransOffset = 24;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 85;
	  section.data(26).dtTransOffset = 25;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 86;
	  section.data(27).dtTransOffset = 26;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 87;
	  section.data(28).dtTransOffset = 27;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 88;
	  section.data(29).dtTransOffset = 28;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 89;
	  section.data(30).dtTransOffset = 29;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 90;
	  section.data(31).dtTransOffset = 30;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 91;
	  section.data(32).dtTransOffset = 31;
	
	  ;% helikopter04day4OptMedFeed_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 92;
	  section.data(33).dtTransOffset = 32;
	
	  ;% helikopter04day4OptMedFeed_P.HILReadEncoder_Active
	  section.data(34).logicalSrcIdx = 93;
	  section.data(34).dtTransOffset = 33;
	
	  ;% helikopter04day4OptMedFeed_P.HILWriteAnalog_Active
	  section.data(35).logicalSrcIdx = 94;
	  section.data(35).dtTransOffset = 34;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(4) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (parameter)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    paramMap.nTotData = nTotData;
    


  ;%**************************
  ;% Create Block Output Map *
  ;%**************************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 1;
    sectIdxOffset = 0;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc sigMap
    ;%
    sigMap.nSections           = nTotSects;
    sigMap.sectIdxOffset       = sectIdxOffset;
      sigMap.sections(nTotSects) = dumSection; %prealloc
    sigMap.nTotData            = -1;
    
    ;%
    ;% Auto data (helikopter04day4OptMedFeed_B)
    ;%
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFeed_B.VandringLavpass
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFeed_B.Add1
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04day4OptMedFeed_B.KalibrerVandring
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04day4OptMedFeed_B.VandringDeriv
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04day4OptMedFeed_B.KalibrerPitch
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04day4OptMedFeed_B.TransferFcn4
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04day4OptMedFeed_B.KalibrerElev
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04day4OptMedFeed_B.Add
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04day4OptMedFeed_B.TransferFcn5
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04day4OptMedFeed_B.Sum2
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04day4OptMedFeed_B.Sum1
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04day4OptMedFeed_B.K_ei
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04day4OptMedFeed_B.SatB
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04day4OptMedFeed_B.Sat
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04day4OptMedFeed_B.Add_f
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      sigMap.sections(1) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (signal)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    sigMap.nTotData = nTotData;
    


  ;%*******************
  ;% Create DWork Map *
  ;%*******************
      
    nTotData      = 0; %add to this count as we go
    nTotSects     = 5;
    sectIdxOffset = 1;
    
    ;%
    ;% Define dummy sections & preallocate arrays
    ;%
    dumSection.nData = -1;  
    dumSection.data  = [];
    
    dumData.logicalSrcIdx = -1;
    dumData.dtTransOffset = -1;
    
    ;%
    ;% Init/prealloc dworkMap
    ;%
    dworkMap.nSections           = nTotSects;
    dworkMap.sectIdxOffset       = sectIdxOffset;
      dworkMap.sections(nTotSects) = dumSection; %prealloc
    dworkMap.nTotData            = -1;
    
    ;%
    ;% Auto data (helikopter04day4OptMedFee_DWork)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 16;
	
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 32;
	
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 36;
	
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 40;
	
	  ;% helikopter04day4OptMedFee_DWork.HILWriteAnalog_Buffer
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 21;
      section.data(21)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFee_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFee_DWork.FromWorkspace1_PWORK.TimePtr
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04day4OptMedFee_DWork.FromWorkspace2_PWORK.TimePtr
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04day4OptMedFee_DWork.E_ref_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04day4OptMedFee_DWork.FromWorkspace_PWORK.TimePtr
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04day4OptMedFee_DWork.P_ref_PWORK.LoggedData
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04day4OptMedFee_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04day4OptMedFee_DWork.ToWorkspace1_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04day4OptMedFee_DWork.ToWorkspace2_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04day4OptMedFee_DWork.ToWorkspace3_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04day4OptMedFee_DWork.ToWorkspace4_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04day4OptMedFee_DWork.ToWorkspace5_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04day4OptMedFee_DWork.elevasion_output_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04day4OptMedFee_DWork.pitch_output_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04day4OptMedFee_DWork.travel_PWORK.LoggedData
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 14;
	
	  ;% helikopter04day4OptMedFee_DWork.Elevasjon_PWORK.LoggedData
	  section.data(16).logicalSrcIdx = 21;
	  section.data(16).dtTransOffset = 15;
	
	  ;% helikopter04day4OptMedFee_DWork.Pitch_PWORK.LoggedData
	  section.data(17).logicalSrcIdx = 22;
	  section.data(17).dtTransOffset = 16;
	
	  ;% helikopter04day4OptMedFee_DWork.Vandring_PWORK.LoggedData
	  section.data(18).logicalSrcIdx = 23;
	  section.data(18).dtTransOffset = 17;
	
	  ;% helikopter04day4OptMedFee_DWork.Bakmotorvolts_PWORK.LoggedData
	  section.data(19).logicalSrcIdx = 24;
	  section.data(19).dtTransOffset = 18;
	
	  ;% helikopter04day4OptMedFee_DWork.Frontmotorvolt_PWORK.LoggedData
	  section.data(20).logicalSrcIdx = 25;
	  section.data(20).dtTransOffset = 19;
	
	  ;% helikopter04day4OptMedFee_DWork.HILWriteAnalog_PWORK
	  section.data(21).logicalSrcIdx = 26;
	  section.data(21).dtTransOffset = 20;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 27;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFee_DWork.HILReadEncoder_Buffer
	  section.data(2).logicalSrcIdx = 28;
	  section.data(2).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFee_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 29;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% helikopter04day4OptMedFee_DWork.FromWorkspace1_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 30;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04day4OptMedFee_DWork.FromWorkspace2_IWORK.PrevIndex
	  section.data(2).logicalSrcIdx = 31;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04day4OptMedFee_DWork.FromWorkspace_IWORK.PrevIndex
	  section.data(3).logicalSrcIdx = 32;
	  section.data(3).dtTransOffset = 2;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(5) = section;
      clear section
      
    
      ;%
      ;% Non-auto Data (dwork)
      ;%
    

    ;%
    ;% Add final counts to struct.
    ;%
    dworkMap.nTotData = nTotData;
    


  ;%
  ;% Add individual maps to base struct.
  ;%

  targMap.paramMap  = paramMap;    
  targMap.signalMap = sigMap;
  targMap.dworkMap  = dworkMap;
  
  ;%
  ;% Add checksums to base struct.
  ;%


  targMap.checksum0 = 2371935453;
  targMap.checksum1 = 3952617480;
  targMap.checksum2 = 1313753260;
  targMap.checksum3 = 3883039318;

