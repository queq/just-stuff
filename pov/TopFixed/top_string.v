module top_string(char, clk, new, btn1, string, completeOut, changeOut);

input [6:0] char;
input clk, new, btn1;
output [76:0] string;
output completeOut, changeOut;

wire complete, change;
wire wCenter, wCene, wCvirgul, wCdelete, wCnum, wDelete, wAdd, wCcounter, wAddEnhe, wLoad, wEnter, wVirgul, wchangeVirgul;
wire [6:0] wMuxOut;
wire [3:0] wCounter;

control control1 (.clk(clk), .cEnter(wCenter), .cEne(wCene), .cDelete(wCdelete), .cCounter(wCcounter), .new(new), .reset(btn1), .cNum(wCnum), .complete(complete), .enter(wEnter), .delete(wDelete), .add(wAdd), .load(wLoad), .addEnhe(wAddEnhe), .change(change), .virgul(wVirgul), .changeVirgul(wchangeVirgul));

charComp charComp1 (.enter(wEnter), .char(char), .cEnter(wCenter), .cEne(wCene), .cVirgul(wCvirgul), .cDelete(wCdelete), .cNum(wCnum));

countComp countComp1 (.counter(wCounter), .cCounter(wCcounter));

counter counter1 (.delete(wDelete), .add(wAdd), .clk(clk), .counter(wCounter), .load(wLoad));

mux mux1 (.char(char), .addEnhe(wAddEnhe), .muxOut(wMuxOut));

shiftString shiftString1 (.load(wLoad), .add(wAdd), .clk(clk), .delete(wDelete), .muxOut(wMuxOut), .string(string));

memory memory1 (.cEnter(wCenter), .cVirgul(wCvirgul), .clk(clk), .enter(wEnter), .virgul(wVirgul), .load(wLoad), .changeVirgul(wchangeVirgul), .addEnhe(wAddEnhe));

adapter adapter1 (.change(change), .complete(complete), .clk(clk), .changeOut(changeOut), .completeOut(completeOut));

endmodule









