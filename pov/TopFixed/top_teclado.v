module top_teclado(Clock, Reset, ClockKeyboard, DataKeyboard, StringDisplay, RS, RW, EN, MsbOD,completeOut,string);

    input Clock;
    input Reset;
    input ClockKeyboard;
	input DataKeyboard;
	output [6:0] StringDisplay;
        output RS, RW, EN;
        output MsbOD;
    output completeOut;

output wire [76:0] string;
wire change;
wire New;
wire [6:0]Char;


	Control_Character Character(.Clock(Clock), .Reset(Reset), .ClockKeyboard(ClockKeyboard), .DataKeyboard(DataKeyboard), .New(New), .Char(Char));

	top_string String (.clk(Clock), .btn1(Reset), .new(New), .char(Char), .string(string), .completeOut(completeOut), .changeOut(change));
	
	Top_Show Show (.clk(Clock), .change(change), .Reset(Reset), .String(string), .StringDisplay(StringDisplay), .RS(RS), .RW(RW), .EN(EN), .MsbOD(MsbOD));
/*
input clk;
				input change, Reset;
				input [76:0] String;   
        output [6:0] StringDisplay;
        output RS, RW, EN; 
        output MsbOD;
*/
/*module Control_Character(
    input Clock,
    input Reset,
    input ClockKeyboard,
	input DataKeyboard,
	output New,
	output [6:0]Ascii

    );*/	


/*module top_string(char, clk, new, btn1, string, complete, change);

input [6:0] char;
input clk, new, btn1;
*/
	
	
endmodule
