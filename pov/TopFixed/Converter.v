`timescale 1ns / 1ps
//////////////////////////////////////////////////////////////////////////////////
// Company: 
// Engineer: 
// 
// Create Date:    12:07:43 05/06/2013 
// Design Name: 
// Module Name:    Converter 
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
module Converter(
	input ScanCodeType,
    input Clock,
    input Reset,
    input [7:0] Actual,
    input [7:0] Anterior,
    output reg [6:0] Ascii,
	 output reg NewAscii

);

	wire [9:0]Entrada;
	reg LoadMayus;
	reg CompShift;
	reg CompMayus;
	reg CompSoltar;
	reg CompAscii;
	reg Mayus;
	reg Shift;

	assign Entrada = {Shift, Mayus^Shift,Actual};
	always @(*)begin
		if (Actual==8'h12)CompShift=1; else CompShift=0;
	end

	always @(*)begin
		if (Actual==8'h58)CompMayus=1; else CompMayus=0;
	end

	always @(*)begin
		if (Anterior==8'hF0)CompSoltar=1; else CompSoltar=0;
	end	

	always@(*)begin
		LoadMayus=(CompMayus && CompSoltar);
	end

	always @(*)begin
		if (Ascii==7'h00)CompAscii=0; else CompAscii=1;
	end

	always @(*) begin
		NewAscii = (CompSoltar && CompAscii);
	end

	always @(posedge Clock)begin
		if(Reset)Mayus=0; else begin 
			if(LoadMayus && ScanCodeType)Mayus=~Mayus;
		end
	end

	always @(posedge Clock)begin
		if(Reset)Shift=0; else begin 
			if(CompShift&&ScanCodeType)Shift=~CompSoltar;
		end
	end
		
	always @(*)begin
		case (Entrada)
	//Alfabeto
	10'h015:Ascii= 7'h71; 
	10'h115:Ascii= 7'h51; 
	10'h215:Ascii= 7'h71; 
	10'h315:Ascii= 7'h51; 
	10'h01D:Ascii= 7'h77; 
	10'h11D:Ascii= 7'h57; 
	10'h21D:Ascii= 7'h77; 
	10'h31D:Ascii= 7'h57; 
	10'h024:Ascii= 7'h65; 
	10'h124:Ascii= 7'h45; 
	10'h224:Ascii= 7'h65; 
	10'h324:Ascii= 7'h45; 
	10'h02D:Ascii= 7'h72; 
	10'h12D:Ascii= 7'h52; 
	10'h22D:Ascii= 7'h72; 
	10'h32D:Ascii= 7'h52; 
	10'h02C:Ascii= 7'h74; 
	10'h12C:Ascii= 7'h54; 
	10'h22C:Ascii= 7'h74; 
	10'h32C:Ascii= 7'h54; 
	10'h035:Ascii= 7'h79; 
	10'h135:Ascii= 7'h59; 
	10'h235:Ascii= 7'h79; 
	10'h335:Ascii= 7'h59; 
	10'h03C:Ascii= 7'h75; 
	10'h13C:Ascii= 7'h55; 
	10'h23C:Ascii= 7'h75; 
	10'h33C:Ascii= 7'h55; 
	10'h043:Ascii= 7'h69; 
	10'h143:Ascii= 7'h49; 
	10'h243:Ascii= 7'h69; 
	10'h343:Ascii= 7'h49; 
	10'h044:Ascii= 7'h6F; 
	10'h144:Ascii= 7'h4F; 
	10'h244:Ascii= 7'h6F; 
	10'h344:Ascii= 7'h4F; 
	10'h04D:Ascii= 7'h70; 
	10'h14D:Ascii= 7'h50; 
	10'h24D:Ascii= 7'h70; 
	10'h34D:Ascii= 7'h50; 
	10'h01C:Ascii= 7'h61; 
	10'h11C:Ascii= 7'h41; 
	10'h21C:Ascii= 7'h61; 
	10'h31C:Ascii= 7'h41; 
	10'h01B:Ascii= 7'h73; 
	10'h11B:Ascii= 7'h53; 
	10'h21B:Ascii= 7'h73; 
	10'h31B:Ascii= 7'h53; 
	10'h023:Ascii= 7'h64; 
	10'h123:Ascii= 7'h44; 
	10'h223:Ascii= 7'h64; 
	10'h323:Ascii= 7'h44; 
	10'h02B:Ascii= 7'h66; 
	10'h12B:Ascii= 7'h46; 
	10'h22B:Ascii= 7'h66; 
	10'h32B:Ascii= 7'h46; 
	10'h034:Ascii= 7'h67; 
	10'h134:Ascii= 7'h47; 
	10'h234:Ascii= 7'h67; 
	10'h334:Ascii= 7'h47; 
	10'h033:Ascii= 7'h68; 
	10'h133:Ascii= 7'h48; 
	10'h233:Ascii= 7'h68; 
	10'h333:Ascii= 7'h48; 
	10'h03B:Ascii= 7'h6A; 
	10'h13B:Ascii= 7'h4A; 
	10'h23B:Ascii= 7'h6A; 
	10'h33B:Ascii= 7'h4A; 
	10'h042:Ascii= 7'h6B; 
	10'h142:Ascii= 7'h4B; 
	10'h242:Ascii= 7'h6B; 
	10'h342:Ascii= 7'h4B; 
	10'h04B:Ascii= 7'h6C; 
	10'h14B:Ascii= 7'h4C; 
	10'h24B:Ascii= 7'h6C; 
	10'h34B:Ascii= 7'h4C; 
	10'h01A:Ascii= 7'h7A; 
	10'h11A:Ascii= 7'h5A; 
	10'h21A:Ascii= 7'h7A; 
	10'h31A:Ascii= 7'h5A; 
	10'h022:Ascii= 7'h78; 
	10'h122:Ascii= 7'h58; 
	10'h222:Ascii= 7'h78; 
	10'h322:Ascii= 7'h58; 
	10'h021:Ascii= 7'h63; 
	10'h121:Ascii= 7'h43; 
	10'h221:Ascii= 7'h63; 
	10'h321:Ascii= 7'h43; 
	10'h02A:Ascii= 7'h76; 
	10'h12A:Ascii= 7'h56; 
	10'h22A:Ascii= 7'h76; 
	10'h32A:Ascii= 7'h56; 
	10'h032:Ascii= 7'h62; 
	10'h132:Ascii= 7'h42; 
	10'h232:Ascii= 7'h62; 
	10'h332:Ascii= 7'h42; 
	10'h031:Ascii= 7'h6E; 
	10'h131:Ascii= 7'h4E; 
	10'h231:Ascii= 7'h6E; 
	10'h331:Ascii= 7'h4E; 
	10'h03A:Ascii= 7'h6D; 
	10'h13A:Ascii= 7'h4D; 
	10'h23A:Ascii= 7'h6D; 
	10'h33A:Ascii= 7'h4D; 

	//Simbolos
	10'h00E:Ascii= 7'h60; 
	10'h10E:Ascii= 7'h60; 
	10'h20E:Ascii= 7'h7E; 
	10'h30E:Ascii= 7'h7E; 
	10'h016:Ascii= 7'h31; 
	10'h116:Ascii= 7'h31; 
	10'h216:Ascii= 7'h21; 
	10'h316:Ascii= 7'h21; 
	10'h01E:Ascii= 7'h32; 
	10'h11E:Ascii= 7'h32; 
	10'h21E:Ascii= 7'h40; 
	10'h31E:Ascii= 7'h40; 
	10'h026:Ascii= 7'h33; 
	10'h126:Ascii= 7'h33; 
	10'h226:Ascii= 7'h23; 
	10'h326:Ascii= 7'h23; 
	10'h025:Ascii= 7'h34; 
	10'h125:Ascii= 7'h34; 
	10'h225:Ascii= 7'h24; 
	10'h325:Ascii= 7'h24; 
	10'h02E:Ascii= 7'h35; 
	10'h12E:Ascii= 7'h35; 
	10'h22E:Ascii= 7'h25; 
	10'h32E:Ascii= 7'h25; 
	10'h036:Ascii= 7'h36; 
	10'h136:Ascii= 7'h36; 
	10'h236:Ascii= 7'h5E; 
	10'h336:Ascii= 7'h5E; 
	10'h03D:Ascii= 7'h37; 
	10'h13D:Ascii= 7'h37; 
	10'h23D:Ascii= 7'h26; 
	10'h33D:Ascii= 7'h26; 
	10'h03E:Ascii= 7'h38; 
	10'h13E:Ascii= 7'h38; 
	10'h23E:Ascii= 7'h2A; 
	10'h33E:Ascii= 7'h2A; 
	10'h046:Ascii= 7'h39; 
	10'h146:Ascii= 7'h39; 
	10'h246:Ascii= 7'h28; 
	10'h346:Ascii= 7'h28; 
	10'h045:Ascii= 7'h30; 
	10'h145:Ascii= 7'h30; 
	10'h245:Ascii= 7'h29; 
	10'h345:Ascii= 7'h29; 
	10'h04E:Ascii= 7'h2D; 
	10'h14E:Ascii= 7'h2D; 
	10'h24E:Ascii= 7'h5F; 
	10'h34E:Ascii= 7'h5F; 
	10'h055:Ascii= 7'h2B; 
	10'h155:Ascii= 7'h2B; 
	10'h255:Ascii= 7'h2B; 
	10'h355:Ascii= 7'h2B; 
	10'h05D:Ascii= 7'h5C; 
	10'h15D:Ascii= 7'h5C; 
	10'h25D:Ascii= 7'h7C; 
	10'h35D:Ascii= 7'h7C; 
	10'h054:Ascii= 7'h5B; 
	10'h154:Ascii= 7'h5B; 
	10'h254:Ascii= 7'h7B; 
	10'h354:Ascii= 7'h7B; 
	10'h05B:Ascii= 7'h5D; 
	10'h15B:Ascii= 7'h5D; 
	10'h25B:Ascii= 7'h7D; 
	10'h35B:Ascii= 7'h7D; 
	10'h04C:Ascii= 7'h3B; 
	10'h14C:Ascii= 7'h3B; 
	10'h24C:Ascii= 7'h3A; 
	10'h34C:Ascii= 7'h3A; 
	10'h052:Ascii= 7'h27; 
	10'h152:Ascii= 7'h27; 
	10'h252:Ascii= 7'h22; 
	10'h352:Ascii= 7'h22; 
	10'h041:Ascii= 7'h2C; 
	10'h141:Ascii= 7'h2C; 
	10'h241:Ascii= 7'h3C; 
	10'h341:Ascii= 7'h3C; 
	10'h049:Ascii= 7'h2E; 
	10'h149:Ascii= 7'h2E; 
	10'h249:Ascii= 7'h3E; 
	10'h349:Ascii= 7'h3E; 
	10'h04A:Ascii= 7'h2F; 
	10'h14A:Ascii= 7'h2F; 
	10'h24A:Ascii= 7'h3F; 
	10'h34A:Ascii= 7'h3F; 

	//Independientes

	10'h066:Ascii= 7'h08;
	10'h166:Ascii= 7'h08;
	10'h266:Ascii= 7'h08;
	10'h366:Ascii= 7'h08;

	10'h029:Ascii= 7'h20;
	10'h129:Ascii= 7'h20;
	10'h229:Ascii= 7'h20;
	10'h329:Ascii= 7'h20;

	10'h05A:Ascii= 7'h04;
	10'h15A:Ascii= 7'h04;
	10'h25A:Ascii= 7'h04;
	10'h35A:Ascii= 7'h04;


	10'h076:Ascii= 7'h1B;
	10'h176:Ascii= 7'h1B;
	10'h276:Ascii= 7'h1B;
	10'h376:Ascii= 7'h1B;


		default: Ascii=7'b0;

	endcase
	end
		
endmodule
