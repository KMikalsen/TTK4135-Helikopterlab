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
    ;% Auto data (helikopter04_P)
    ;%
      section.nData     = 48;
      section.data(48)  = dumData; %prealloc
      
	  ;% helikopter04_P.HILInitialize_OOStart
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_P.HILInitialize_OOEnter
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04_P.HILInitialize_OOTerminate
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04_P.HILInitialize_OOExit
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04_P.HILInitialize_AIHigh
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04_P.HILInitialize_AILow
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04_P.HILInitialize_AOHigh
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04_P.HILInitialize_AOLow
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04_P.HILInitialize_AOInitial
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04_P.HILInitialize_AOFinal
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04_P.KalibrerElev_Gain
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04_P.Constant_Value
	  section.data(12).logicalSrcIdx = 11;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04_P.Constant1_Value
	  section.data(13).logicalSrcIdx = 12;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04_P.VandringLavpass_A
	  section.data(14).logicalSrcIdx = 13;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04_P.VandringLavpass_C
	  section.data(15).logicalSrcIdx = 14;
	  section.data(15).dtTransOffset = 14;
	
	  ;% helikopter04_P.KalibrerVandring_Gain
	  section.data(16).logicalSrcIdx = 17;
	  section.data(16).dtTransOffset = 15;
	
	  ;% helikopter04_P.VandringDeriv_A
	  section.data(17).logicalSrcIdx = 18;
	  section.data(17).dtTransOffset = 16;
	
	  ;% helikopter04_P.VandringDeriv_C
	  section.data(18).logicalSrcIdx = 19;
	  section.data(18).dtTransOffset = 17;
	
	  ;% helikopter04_P.VandringDeriv_D
	  section.data(19).logicalSrcIdx = 20;
	  section.data(19).dtTransOffset = 18;
	
	  ;% helikopter04_P.KalibrerPitch_Gain
	  section.data(20).logicalSrcIdx = 22;
	  section.data(20).dtTransOffset = 19;
	
	  ;% helikopter04_P.TransferFcn4_A
	  section.data(21).logicalSrcIdx = 23;
	  section.data(21).dtTransOffset = 20;
	
	  ;% helikopter04_P.TransferFcn4_C
	  section.data(22).logicalSrcIdx = 24;
	  section.data(22).dtTransOffset = 21;
	
	  ;% helikopter04_P.TransferFcn4_D
	  section.data(23).logicalSrcIdx = 25;
	  section.data(23).dtTransOffset = 22;
	
	  ;% helikopter04_P.TransferFcn5_A
	  section.data(24).logicalSrcIdx = 27;
	  section.data(24).dtTransOffset = 23;
	
	  ;% helikopter04_P.TransferFcn5_C
	  section.data(25).logicalSrcIdx = 28;
	  section.data(25).dtTransOffset = 24;
	
	  ;% helikopter04_P.TransferFcn5_D
	  section.data(26).logicalSrcIdx = 29;
	  section.data(26).dtTransOffset = 25;
	
	  ;% helikopter04_P.Gain_Gain
	  section.data(27).logicalSrcIdx = 31;
	  section.data(27).dtTransOffset = 26;
	
	  ;% helikopter04_P.Gain1_Gain
	  section.data(28).logicalSrcIdx = 32;
	  section.data(28).dtTransOffset = 62;
	
	  ;% helikopter04_P.Integrator_IC
	  section.data(29).logicalSrcIdx = 33;
	  section.data(29).dtTransOffset = 66;
	
	  ;% helikopter04_P.Integrator_UpperSat
	  section.data(30).logicalSrcIdx = 34;
	  section.data(30).dtTransOffset = 67;
	
	  ;% helikopter04_P.Integrator_LowerSat
	  section.data(31).logicalSrcIdx = 35;
	  section.data(31).dtTransOffset = 68;
	
	  ;% helikopter04_P.K_ed_Gain
	  section.data(32).logicalSrcIdx = 36;
	  section.data(32).dtTransOffset = 69;
	
	  ;% helikopter04_P.elevation_Value
	  section.data(33).logicalSrcIdx = 37;
	  section.data(33).dtTransOffset = 70;
	
	  ;% helikopter04_P.K_ei_Gain
	  section.data(34).logicalSrcIdx = 38;
	  section.data(34).dtTransOffset = 71;
	
	  ;% helikopter04_P.K_ep_Gain
	  section.data(35).logicalSrcIdx = 39;
	  section.data(35).dtTransOffset = 72;
	
	  ;% helikopter04_P.Saturation_UpperSat
	  section.data(36).logicalSrcIdx = 40;
	  section.data(36).dtTransOffset = 73;
	
	  ;% helikopter04_P.Saturation_LowerSat
	  section.data(37).logicalSrcIdx = 41;
	  section.data(37).dtTransOffset = 74;
	
	  ;% helikopter04_P.Saturation_UpperSat_m
	  section.data(38).logicalSrcIdx = 42;
	  section.data(38).dtTransOffset = 75;
	
	  ;% helikopter04_P.Saturation_LowerSat_f
	  section.data(39).logicalSrcIdx = 43;
	  section.data(39).dtTransOffset = 76;
	
	  ;% helikopter04_P.K_pp_Gain
	  section.data(40).logicalSrcIdx = 44;
	  section.data(40).dtTransOffset = 77;
	
	  ;% helikopter04_P.K_pd_Gain
	  section.data(41).logicalSrcIdx = 45;
	  section.data(41).dtTransOffset = 78;
	
	  ;% helikopter04_P.Gain2_Gain
	  section.data(42).logicalSrcIdx = 46;
	  section.data(42).dtTransOffset = 79;
	
	  ;% helikopter04_P.SatB_UpperSat
	  section.data(43).logicalSrcIdx = 47;
	  section.data(43).dtTransOffset = 80;
	
	  ;% helikopter04_P.SatB_LowerSat
	  section.data(44).logicalSrcIdx = 48;
	  section.data(44).dtTransOffset = 81;
	
	  ;% helikopter04_P.Gain1_Gain_g
	  section.data(45).logicalSrcIdx = 49;
	  section.data(45).dtTransOffset = 82;
	
	  ;% helikopter04_P.Sat_UpperSat
	  section.data(46).logicalSrcIdx = 50;
	  section.data(46).dtTransOffset = 83;
	
	  ;% helikopter04_P.Sat_LowerSat
	  section.data(47).logicalSrcIdx = 51;
	  section.data(47).dtTransOffset = 84;
	
	  ;% helikopter04_P.Constant_Value_n
	  section.data(48).logicalSrcIdx = 52;
	  section.data(48).dtTransOffset = 85;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(1) = section;
      clear section
      
      section.nData     = 3;
      section.data(3)  = dumData; %prealloc
      
	  ;% helikopter04_P.HILInitialize_CKChannels
	  section.data(1).logicalSrcIdx = 53;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_P.HILInitialize_CKModes
	  section.data(2).logicalSrcIdx = 54;
	  section.data(2).dtTransOffset = 6;
	
	  ;% helikopter04_P.HILInitialize_EIInitial
	  section.data(3).logicalSrcIdx = 55;
	  section.data(3).dtTransOffset = 7;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(2) = section;
      clear section
      
      section.nData     = 5;
      section.data(5)  = dumData; %prealloc
      
	  ;% helikopter04_P.HILInitialize_AIChannels
	  section.data(1).logicalSrcIdx = 56;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_P.HILInitialize_AOChannels
	  section.data(2).logicalSrcIdx = 57;
	  section.data(2).dtTransOffset = 16;
	
	  ;% helikopter04_P.HILInitialize_EIQuadrature
	  section.data(3).logicalSrcIdx = 58;
	  section.data(3).dtTransOffset = 20;
	
	  ;% helikopter04_P.HILReadEncoder_Channels
	  section.data(4).logicalSrcIdx = 59;
	  section.data(4).dtTransOffset = 21;
	
	  ;% helikopter04_P.HILWriteAnalog_Channels
	  section.data(5).logicalSrcIdx = 60;
	  section.data(5).dtTransOffset = 24;
	
      nTotData = nTotData + section.nData;
      paramMap.sections(3) = section;
      clear section
      
      section.nData     = 35;
      section.data(35)  = dumData; %prealloc
      
	  ;% helikopter04_P.HILInitialize_Active
	  section.data(1).logicalSrcIdx = 61;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_P.HILInitialize_CKPStart
	  section.data(2).logicalSrcIdx = 62;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04_P.HILInitialize_CKPEnter
	  section.data(3).logicalSrcIdx = 63;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04_P.HILInitialize_AIPStart
	  section.data(4).logicalSrcIdx = 64;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04_P.HILInitialize_AIPEnter
	  section.data(5).logicalSrcIdx = 65;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04_P.HILInitialize_AOPStart
	  section.data(6).logicalSrcIdx = 66;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04_P.HILInitialize_AOPEnter
	  section.data(7).logicalSrcIdx = 67;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04_P.HILInitialize_AOStart
	  section.data(8).logicalSrcIdx = 68;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04_P.HILInitialize_AOEnter
	  section.data(9).logicalSrcIdx = 69;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04_P.HILInitialize_AOTerminate
	  section.data(10).logicalSrcIdx = 70;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04_P.HILInitialize_AOExit
	  section.data(11).logicalSrcIdx = 71;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04_P.HILInitialize_AOReset
	  section.data(12).logicalSrcIdx = 72;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04_P.HILInitialize_DOPStart
	  section.data(13).logicalSrcIdx = 73;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04_P.HILInitialize_DOPEnter
	  section.data(14).logicalSrcIdx = 74;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04_P.HILInitialize_DOStart
	  section.data(15).logicalSrcIdx = 75;
	  section.data(15).dtTransOffset = 14;
	
	  ;% helikopter04_P.HILInitialize_DOEnter
	  section.data(16).logicalSrcIdx = 76;
	  section.data(16).dtTransOffset = 15;
	
	  ;% helikopter04_P.HILInitialize_DOTerminate
	  section.data(17).logicalSrcIdx = 77;
	  section.data(17).dtTransOffset = 16;
	
	  ;% helikopter04_P.HILInitialize_DOExit
	  section.data(18).logicalSrcIdx = 78;
	  section.data(18).dtTransOffset = 17;
	
	  ;% helikopter04_P.HILInitialize_DOReset
	  section.data(19).logicalSrcIdx = 79;
	  section.data(19).dtTransOffset = 18;
	
	  ;% helikopter04_P.HILInitialize_EIPStart
	  section.data(20).logicalSrcIdx = 80;
	  section.data(20).dtTransOffset = 19;
	
	  ;% helikopter04_P.HILInitialize_EIPEnter
	  section.data(21).logicalSrcIdx = 81;
	  section.data(21).dtTransOffset = 20;
	
	  ;% helikopter04_P.HILInitialize_EIStart
	  section.data(22).logicalSrcIdx = 82;
	  section.data(22).dtTransOffset = 21;
	
	  ;% helikopter04_P.HILInitialize_EIEnter
	  section.data(23).logicalSrcIdx = 83;
	  section.data(23).dtTransOffset = 22;
	
	  ;% helikopter04_P.HILInitialize_POPStart
	  section.data(24).logicalSrcIdx = 84;
	  section.data(24).dtTransOffset = 23;
	
	  ;% helikopter04_P.HILInitialize_POPEnter
	  section.data(25).logicalSrcIdx = 85;
	  section.data(25).dtTransOffset = 24;
	
	  ;% helikopter04_P.HILInitialize_POStart
	  section.data(26).logicalSrcIdx = 86;
	  section.data(26).dtTransOffset = 25;
	
	  ;% helikopter04_P.HILInitialize_POEnter
	  section.data(27).logicalSrcIdx = 87;
	  section.data(27).dtTransOffset = 26;
	
	  ;% helikopter04_P.HILInitialize_POTerminate
	  section.data(28).logicalSrcIdx = 88;
	  section.data(28).dtTransOffset = 27;
	
	  ;% helikopter04_P.HILInitialize_POExit
	  section.data(29).logicalSrcIdx = 89;
	  section.data(29).dtTransOffset = 28;
	
	  ;% helikopter04_P.HILInitialize_POReset
	  section.data(30).logicalSrcIdx = 90;
	  section.data(30).dtTransOffset = 29;
	
	  ;% helikopter04_P.HILInitialize_OOReset
	  section.data(31).logicalSrcIdx = 91;
	  section.data(31).dtTransOffset = 30;
	
	  ;% helikopter04_P.HILInitialize_DOInitial
	  section.data(32).logicalSrcIdx = 92;
	  section.data(32).dtTransOffset = 31;
	
	  ;% helikopter04_P.HILInitialize_DOFinal
	  section.data(33).logicalSrcIdx = 93;
	  section.data(33).dtTransOffset = 32;
	
	  ;% helikopter04_P.HILReadEncoder_Active
	  section.data(34).logicalSrcIdx = 94;
	  section.data(34).dtTransOffset = 33;
	
	  ;% helikopter04_P.HILWriteAnalog_Active
	  section.data(35).logicalSrcIdx = 95;
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
    ;% Auto data (helikopter04_B)
    ;%
      section.nData     = 11;
      section.data(11)  = dumData; %prealloc
      
	  ;% helikopter04_B.KalibrerElev
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_B.Add
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04_B.VandringLavpass
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04_B.Add1
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04_B.KalibrerVandring
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04_B.KalibrerPitch
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04_B.Sum1
	  section.data(7).logicalSrcIdx = 6;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04_B.K_ei
	  section.data(8).logicalSrcIdx = 7;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04_B.SatB
	  section.data(9).logicalSrcIdx = 8;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04_B.Sat
	  section.data(10).logicalSrcIdx = 9;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04_B.Add_m
	  section.data(11).logicalSrcIdx = 10;
	  section.data(11).dtTransOffset = 10;
	
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
    ;% Auto data (helikopter04_DWork)
    ;%
      section.nData     = 6;
      section.data(6)  = dumData; %prealloc
      
	  ;% helikopter04_DWork.HILInitialize_AIMinimums
	  section.data(1).logicalSrcIdx = 0;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_DWork.HILInitialize_AIMaximums
	  section.data(2).logicalSrcIdx = 1;
	  section.data(2).dtTransOffset = 16;
	
	  ;% helikopter04_DWork.HILInitialize_AOMinimums
	  section.data(3).logicalSrcIdx = 2;
	  section.data(3).dtTransOffset = 32;
	
	  ;% helikopter04_DWork.HILInitialize_AOMaximums
	  section.data(4).logicalSrcIdx = 3;
	  section.data(4).dtTransOffset = 36;
	
	  ;% helikopter04_DWork.HILInitialize_AOVoltages
	  section.data(5).logicalSrcIdx = 4;
	  section.data(5).dtTransOffset = 40;
	
	  ;% helikopter04_DWork.HILWriteAnalog_Buffer
	  section.data(6).logicalSrcIdx = 5;
	  section.data(6).dtTransOffset = 44;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(1) = section;
      clear section
      
      section.nData     = 15;
      section.data(15)  = dumData; %prealloc
      
	  ;% helikopter04_DWork.HILReadEncoder_PWORK
	  section.data(1).logicalSrcIdx = 6;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_DWork.ToWorkspace_PWORK.LoggedData
	  section.data(2).logicalSrcIdx = 7;
	  section.data(2).dtTransOffset = 1;
	
	  ;% helikopter04_DWork.ToWorkspace1_PWORK.LoggedData
	  section.data(3).logicalSrcIdx = 8;
	  section.data(3).dtTransOffset = 2;
	
	  ;% helikopter04_DWork.elevasion_output_PWORK.LoggedData
	  section.data(4).logicalSrcIdx = 9;
	  section.data(4).dtTransOffset = 3;
	
	  ;% helikopter04_DWork.FromWorkspace1_PWORK.TimePtr
	  section.data(5).logicalSrcIdx = 10;
	  section.data(5).dtTransOffset = 4;
	
	  ;% helikopter04_DWork.FromWorkspace_PWORK.TimePtr
	  section.data(6).logicalSrcIdx = 11;
	  section.data(6).dtTransOffset = 5;
	
	  ;% helikopter04_DWork.pitch_in_PWORK.LoggedData
	  section.data(7).logicalSrcIdx = 12;
	  section.data(7).dtTransOffset = 6;
	
	  ;% helikopter04_DWork.pitch_output_PWORK.LoggedData
	  section.data(8).logicalSrcIdx = 13;
	  section.data(8).dtTransOffset = 7;
	
	  ;% helikopter04_DWork.travel_PWORK.LoggedData
	  section.data(9).logicalSrcIdx = 14;
	  section.data(9).dtTransOffset = 8;
	
	  ;% helikopter04_DWork.Elevasjon_PWORK.LoggedData
	  section.data(10).logicalSrcIdx = 15;
	  section.data(10).dtTransOffset = 9;
	
	  ;% helikopter04_DWork.Pitch_PWORK.LoggedData
	  section.data(11).logicalSrcIdx = 16;
	  section.data(11).dtTransOffset = 10;
	
	  ;% helikopter04_DWork.Vandring_PWORK.LoggedData
	  section.data(12).logicalSrcIdx = 17;
	  section.data(12).dtTransOffset = 11;
	
	  ;% helikopter04_DWork.Bakmotorvolts_PWORK.LoggedData
	  section.data(13).logicalSrcIdx = 18;
	  section.data(13).dtTransOffset = 12;
	
	  ;% helikopter04_DWork.Frontmotorvolt_PWORK.LoggedData
	  section.data(14).logicalSrcIdx = 19;
	  section.data(14).dtTransOffset = 13;
	
	  ;% helikopter04_DWork.HILWriteAnalog_PWORK
	  section.data(15).logicalSrcIdx = 20;
	  section.data(15).dtTransOffset = 14;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(2) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% helikopter04_DWork.HILInitialize_ClockModes
	  section.data(1).logicalSrcIdx = 21;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_DWork.HILReadEncoder_Buffer
	  section.data(2).logicalSrcIdx = 22;
	  section.data(2).dtTransOffset = 6;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(3) = section;
      clear section
      
      section.nData     = 1;
      section.data(1)  = dumData; %prealloc
      
	  ;% helikopter04_DWork.HILInitialize_Card
	  section.data(1).logicalSrcIdx = 23;
	  section.data(1).dtTransOffset = 0;
	
      nTotData = nTotData + section.nData;
      dworkMap.sections(4) = section;
      clear section
      
      section.nData     = 2;
      section.data(2)  = dumData; %prealloc
      
	  ;% helikopter04_DWork.FromWorkspace1_IWORK.PrevIndex
	  section.data(1).logicalSrcIdx = 24;
	  section.data(1).dtTransOffset = 0;
	
	  ;% helikopter04_DWork.FromWorkspace_IWORK.PrevIndex
	  section.data(2).logicalSrcIdx = 25;
	  section.data(2).dtTransOffset = 1;
	
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


  targMap.checksum0 = 2170064209;
  targMap.checksum1 = 3197341573;
  targMap.checksum2 = 2189218525;
  targMap.checksum3 = 2132371646;

