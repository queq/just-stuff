module topTarjeta(Clock, Reset, ClockKeyboard, DataKeyboard, RS, RW, EN, MsbOD,StringDisplay,SendBit);

input Clock;
input Reset;
input ClockKeyboard;
input DataKeyboard;

output RS;
output RW;
output EN;
output MsbOD;
output [6:0]StringDisplay;

output SendBit;

wire wComplete;
wire [76:0] wStringPOV;

	
	top_teclado Teclado (
	.Clock(Clock),
	.Reset(Reset),
	.ClockKeyboard(ClockKeyboard),
	.DataKeyboard(DataKeyboard),
	.RS(RS),
	.RW(RW),
	.EN(EN),
	.MsbOD(MsbOD),
	.StringDisplay(StringDisplay),
	.string(wStringPOV),
	.completeOut(wComplete)
	);
	
	topTransmitter Transmitter (
	.StringPOV(wStringPOV),
	.Complete(wComplete),
	.clk(Clock),
	.Reset(Reset),
	.SendBit(SendBit)
	);







endmodule
