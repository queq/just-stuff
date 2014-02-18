`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    23:00:42 01/05/2013 
// Design Name: 
// Module Name:    Control_Character 
// Project Name: 	 P.O.V
// Target Devices: 
// Tool versions: 
// Description: 
//
// Dependencies: 
//
// Revision: 
// Revision 0.01 - File Created
// Additional Comments: 
//
//////////////////////////////////////////////////////////////////////////////////
module Control_Character(
    input Clock,
    input Reset,
    input ClockKeyboard,
	input DataKeyboard,
	output New,
	output [6:0]Char

    );

	wire NewScanCode;
	wire ScanCodeType;
	wire LoadDato;
	wire LoadChar;
	wire NewAscii;
	wire [7:0]Anterior;
	wire [7:0]Actual;
	wire [7:0]ScanCode;
	wire [6:0]Ascii;

	

	
	MaquinaDeControl Maquina_Control(.Clock(Clock), .Reset(Reset), .NewScanCode(NewScanCode), .NewAscii(NewAscii), .LoadDato(LoadDato), .LoadChar(LoadChar), .ScanCodeType(ScanCodeType));

	Anterior_Actual Anterior_Actual_Module(.Clock(Clock), .Reset(Reset), .LoadDato(LoadDato), .Dato(ScanCode), .Anterior(Anterior), .Actual(Actual));

	Converter Convertir(.Clock(Clock), .Reset(Reset), .ScanCodeType(ScanCodeType), .Actual(Actual), .Ascii(Ascii), .NewAscii(NewAscii), .Anterior(Anterior));

	Char_Ascii Converter_Ascii(.Clock(Clock), .Reset(Reset), .LoadChar(LoadChar), .Ascii(Ascii), .New(New), .Char(Char));

	ScanCodeModule ScanCode_Module(.Clk(Clock), .Reset(Reset), .ClkKB(ClockKeyboard), .DataKB(DataKeyboard), .NewScanCode(NewScanCode), .ScanCode(ScanCode));
	
endmodule
