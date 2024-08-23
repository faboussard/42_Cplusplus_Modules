#include "FragTrap.hpp"

int main() {
	// Create a FragTrap instance
	FragTrap frag("Fraggy");

	// Test normal attack
	frag.attack("target1");

	// Test FragTrap-specific behavior
	frag.highFivesGuys();

	// Test damage and repair
	frag.takeDamage(20);  // Assume FragTrap inherits from ClapTrap and has takeDamage method
	frag.beRepaired(10);  // Assume FragTrap inherits from ClapTrap and has beRepaired method

	// Test energy exhaustion
	frag.takeDamage(80);  // Bring hit points close to zero
	frag.attack("target2");  // Should be allowed (1 energy point left)
	frag.attack("target3");  // Should fail due to no energy left

	// Test copying
	FragTrap fragCopy(frag);  // Copy constructor
	fragCopy.attack("target4");
	fragCopy.highFivesGuys();

	// Test assignment operator
	FragTrap fragAssigned("AssignedFrag");
	fragAssigned = frag;  // Assignment operator
	fragAssigned.attack("target5");
	fragAssigned.highFivesGuys();

	// Deplete hit points and test behavior
	frag.takeDamage(100);  // Set hit points to zero
	frag.beRepaired(20);  // Should not repair since hit points are zero

	// Test copying or assigning a "dead" FragTrap
	FragTrap fragDeadCopy(frag);  // Copying a "dead" FragTrap
	fragDeadCopy.attack("target6");  // Should not attack because it's "dead"

	FragTrap fragAssignedDead("AnotherAssignedFrag");
	fragAssignedDead = frag;  // Assigning a "dead" FragTrap
	fragAssignedDead.attack("target7");  // Should not attack because it's "dead"

	return 0;
}

