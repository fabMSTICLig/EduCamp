difference()
{
    union(){
        cylinder(r=7,h=20);
        translate([0,0,20])cylinder(r1=9, r2=7,h=5);
        translate([0,0,15])cylinder(r1=7, r2=9,h=5);
    }
    cylinder(r=4,h=20);
    translate([0,0,20])cylinder(r=6,h=5);
}