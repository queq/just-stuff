`timescale 1ns / 1ps
module ram (
input clk,
input[7:0] direccionram,
input wram,
input [15:0]datorom,
output reg [15:0]datoram
);
parameter DWIDTH=16,AWIDTH=8,WORDS=256;
 
reg [DWIDTH-1:0] ram [WORDS-1:0];
       ////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////
       //////CALCULA LA DIRECCION DE LA RAM PARA LECTURA Y HACE LECTURA Y ESCRITURA.  
always@(posedge clk ) 
         if (wram) begin  datoram <= ram[direccionram]; end    // se escribe y escribe la ram
         else   ram[direccionram] <= datorom;                                                /// se lee la ram
  endmodule
