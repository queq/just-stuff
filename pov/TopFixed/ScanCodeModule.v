`timescale 1ns / 1ps
module ScanCodeModule(Clk,Reset, ClkKB, DataKB,NewScanCode, ScanCode);
	input Clk,Reset,ClkKB, DataKB;
	wire NewDataKB;
	output NewScanCode;
	output [7:0] ScanCode;
	wire Load, New,Borrar,EndTras,ParityCoherente;
	reg ClkKB_syn, DataKB_syn ;

always @(negedge Clk) begin
  ClkKB_syn <= ClkKB;
  DataKB_syn <= DataKB;
end

//module module Muestrear(ClkKB, NewDataKB, Clk , Reset);
  Muestrear Muestrear (.Clk(Clk), .Reset(Reset),.ClkKB(ClkKB_syn), .NewDataKB(NewDataKB) );

//module ScanCodeControl(NewDataKB,Load, New , Borrar, EndTras, ParityCoherente, Clk , Reset);
 ScanCodeControl Control (.Clk(Clk), .Reset(Reset),.NewDataKB(NewDataKB), .Load(Load) , .New(New), .Borrar(Borrar), .EndTras(EndTras), .ParityCoherente(ParityCoherente));

//module ModuloDato(Clk, Reset, DataKB,Load, New,Borrar,EndTras,ParityCoherente ,NewScanCode, ScanCode)
 ModuloDato Dato (.Clk(Clk), .Reset(Reset), .DataKB(DataKB_syn), .NewScanCode(NewScanCode), .ScanCode(ScanCode), .Load(Load), .Borrar(Borrar), .EndTras(EndTras), .ParityCoherente(ParityCoherente),.New(New));

endmodule
