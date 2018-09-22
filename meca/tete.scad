difference()
{
    union(){
        sphere(r=40);
        translate([0,45,12])rotate([90,0,0])cylinder(r=10,h=20);
    }
    sphere(r=39);
    translate([0,0,-20])cube([80,80,40], center=true);
    translate([0,45,12.5])rotate([90,0,0])cylinder(r=8,h=20);
}