 `timescale 1ns / 1ps

module rom #(parameter mem_file_name = "Memory.txt") (input clk, input leer_rom,input [10:0]dir_rom, output reg [15:0]dato_rom);
 parameter DWIDTH=16,AWIDTH=11,WORDS=2048;
 
reg [0:DWIDTH-1] mem [WORDS-1:0];//dddddddddddddddd
 
 initial $readmemh(mem_file_name, mem);
 
always@(posedge clk)
                  begin
                     if(leer_rom==1'b1) dato_rom <= mem[dir_rom+0];  //se lee la rom
                      else 
                           dato_rom <=  16'b0;	  
                  end
 
endmodule
