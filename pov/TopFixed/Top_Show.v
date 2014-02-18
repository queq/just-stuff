module Top_Show(clk, change, Reset, String, RS, RW, EN, StringDisplay, MsbOD);
				input clk;
				input change, Reset;
				input [76:0] String;   
        output [6:0] StringDisplay;
        output RS, RW, EN; 
        output MsbOD;
        wire [76:0] w_Regin;
        wire [6:0] w_D;
				wire [2:0] w_scrinit;
        wire w_Init,w_Shift, w_enhe, w_Z, w_creaenhe, w_Start, w_outcont, w_rst, w_Beg, w_Ready, w_Cycend;

Timer Timer1(.rst(w_rst), .clk(clk), .Beg(w_Beg), .Ready(w_Ready), .Cycend(w_Cycend), .scrinit(w_scrinit));       

StringInput StringInput1(.String(String), .Init(w_Init), .clk(clk), .Shift(w_Shift), .rst(w_rst), .Regin(w_Regin));

Accumulator Accumulator1(.MsbR(w_Regin[76]), .Shift(w_Shift), .clk(clk), .D(w_D), .rst(w_rst));

Enhecomp Enhecomp1(.D(w_D), .enhe(w_enhe));

Zerocomp Zerocomp1(.Regin(w_Regin), .Z(w_Z));

Create Create1(.Init(w_Init), .creaenhe(w_creaenhe), .D(w_D), .rst(w_rst), .MsbOD(MsbOD), .RS(RS), .RW(RW), .Out_display(StringDisplay), .clk(clk), .scrinit(w_scrinit));

SevenCont SevenCont1(.Start(w_Start), .rst(w_rst), .clk(clk), .outcont(w_outcont));

ShowControl ShowControl1(.clk(clk), .enhe(w_enhe), .outcont(w_outcont), .Reset(Reset), .change(change), .Z(w_Z), .Start(w_Start), .EN(EN), .creaenhe(w_creaenhe), .Init(w_Init), .Shift(w_Shift), .Ready(w_Ready), .rst(w_rst), .Beg(w_Beg), .scrinit(w_scrinit), .Cycend(w_Cycend));

endmodule
