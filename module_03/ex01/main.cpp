#include "ScavTrap.hpp"

int main() {
	// Creating a ScavTrap instance
	ScavTrap scav("Scavvy");

	// Test normal attack
	scav.attack("target1");

	// Test damage and repair
	scav.takeDamage(20);
	scav.beRepaired(10);

	// Test ScavTrap specific behavior
	scav.guardGate();

	// Test energy exhaustion
	scav.takeDamage(80); // brings hit points close to zero
	scav.attack("target2"); // should be allowed (1 energy point left)
	scav.attack("target3"); // should fail due to no energy left

	// Test destruction after copying
	ScavTrap scavCopy(scav); // copying scav
	scavCopy.attack("target4");

	// Test assignment operator
	ScavTrap scavAssigned("AssignedScav");
	scavAssigned = scav; // assign scav to scavAssigned
	scavAssigned.attack("target5");

	// Now, let's deplete Scavvy's hit points to zero
	scav.takeDamage(100);
	scav.beRepaired(20); // Should not repair since hit points are zero

	// Finally, let's check what happens when copying or assigning a "dead" ScavTrap
	ScavTrap scavDeadCopy(scav); // Copying the dead ScavTrap
	scavDeadCopy.attack("target6"); // Should not attack because it's "dead"

	ScavTrap scavAssignedDead("AnotherAssignedScav");
	scavAssignedDead = scav; // Assigning the dead ScavTrap
	scavAssignedDead.attack("target7"); // Should not attack because it's "dead"

	return 0;
}
