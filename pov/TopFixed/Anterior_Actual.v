`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:06:26 05/06/2013 
// Design Name: 
// Module Name:    Anterior_Actual 
// Project Name: 
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
module Anterior_Actual(
    input Clock,
    input Reset,
    input LoadDato,
    input [7:0]Dato,
    output reg [7:0]Anterior,
    output reg [7:0]Actual
);

always @(posedge Clock)begin
	if(Reset==1)begin 
		Anterior=8'h0; 
		Actual=8'h0; 
	end else begin 
		if(LoadDato==1)begin 
			Anterior=Actual;	
			Actual=Dato;
		end
	end
end
	
endmodule 
