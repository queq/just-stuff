module ModuloDato(Clk, Reset, DataKB,Load, New,Borrar,EndTras,ParityCoherente ,NewScanCode, ScanCode);
	input Clk, Reset, DataKB,Load, New,Borrar;
	output reg ParityCoherente, NewScanCode;
	output EndTras;
	output [7:0]ScanCode;
	reg [10:0] Dato;
	reg [11:0] Aux;
always @(posedge Clk) begin
	if(Reset)begin
		Aux={1'b1,11'b0};
		Dato=11'b0;
		NewScanCode=0;	
	end else begin
		if(Load) Dato={DataKB,Dato[10:1]};
		if (Borrar)	Aux={1'b1,11'b0};	
		else if(Load) Aux={1'b0,Aux[11:1]};
		if(New)NewScanCode=1;
		else NewScanCode=0;
	end
end

always@(*)begin
	ParityCoherente= (^Dato[9:1])&&(Dato[0]==0)&&(Dato[10]==1);
end
	assign ScanCode=Dato[8:1];
	assign EndTras=Aux[0];
	
endmodule
