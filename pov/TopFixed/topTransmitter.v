module topTransmitter ( StringPOV, Complete, clk, Reset, SendBit);


	input [0:76] StringPOV;
	input Complete, clk, Reset;
	output SendBit;
		
	wire wLoadString;
	wire wCompareString;
	wire wLoadNextChar;
	wire wGenerateData;
	wire wSendData;
	wire wNullString;
	wire wNullDataChar;
	wire wGenerated;

	wire [0:76] wString;
	wire [0:6] wChar;
	wire [0:9] wDataChar;
	wire wParityBit;
	wire wclkSend;
	
	controlTransmitter topControl (
	.Complete(Complete),
	.NullString(wNullString),
	.NullDataChar(wNullDataChar),
	.Generated(wGenerated),
	.LoadString(wLoadString),
	.CompareString(wCompareString),
	.LoadNextChar(wLoadNextChar),
	.GenerateData(wGenerateData),
	.SendData(wSendData),
	.clk(clk),
	.Reset(Reset)
	);
	
	comparer topComparer (
	.String(wString),
	.CompareString(wCompareString),
	.NullString(wNullString),
	.DataChar(wDataChar),
	.NullDataChar(wNullDataChar)
	);
	
	stringCharLoader topStringCharLoader (
	.Char(wChar),
	.StringPOV(StringPOV),
	.LoadString(wLoadString),
	.LoadNextChar(wLoadNextChar),
	.clk(clk),
	.Reset(Reset),
	.String(wString)
	);
	
	parityCreator topParityCreator (
	.Char(wChar),
	.ParityBit(wParityBit)
	);

	frequencyDivider topFrequencyDivider (
	.clk(clk),
	.clkSend(wclkSend),
	.Reset(Reset)
	);

	bitSender topBitSender (
	.Char(wChar),
	.ParityBit(wParityBit),
	.GenerateData(wGenerateData),
	.SendData(wSendData),
	.Reset(Reset),
	.clk(clk),
	.clkSend(wclkSend),
	.SendBit(SendBit),
	.DataChar(wDataChar),
	.Generated(wGenerated)
	);

	
endmodule
