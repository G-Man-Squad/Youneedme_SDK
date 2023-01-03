//========= Copyright Valve Corporation, All rights reserved. ============//
//
// Purpose:
//
//=============================================================================//

#ifndef WEAPON_SUITCASE_H
#define WEAPON_SUITCASE_H

#include "basebludgeonweapon.h"

#if defined( _WIN32 )
#pragma once
#endif

#ifdef HL2MP
#error weapon_crowbar.h must not be included in hl2mp. The windows compiler will use the wrong class elsewhere if it is.
#endif

#define	SUITCASE_RANGE	85.0f
#define	SUITCASE_REFIRE	0.6f

//-----------------------------------------------------------------------------
// CWeaponSuitcase
//-----------------------------------------------------------------------------

class CWeaponSuitcase : public CBaseHLBludgeonWeapon
{
public:
	DECLARE_CLASS( CWeaponSuitcase, CBaseHLBludgeonWeapon );

	DECLARE_SERVERCLASS();
	DECLARE_ACTTABLE();

	CWeaponSuitcase();

	float		GetRange( void )		{	return	SUITCASE_RANGE;	}
	float		GetFireRate( void )		{	return	SUITCASE_REFIRE;	}

	void		AddViewKick( void );
	float		GetDamageForActivity( Activity hitActivity );

	virtual int WeaponMeleeAttack1Condition( float flDot, float flDist );
	void		SecondaryAttack( void )	{	return;	}

	// Animation event
	virtual void Operator_HandleAnimEvent( animevent_t *pEvent, CBaseCombatCharacter *pOperator );

#ifdef MAPBASE
	// Don't use backup activities
	acttable_t		*GetBackupActivityList() { return NULL; }
	int				GetBackupActivityListCount() { return 0; }
#endif

private:
	// Animation event handlers
	void HandleAnimEventMeleeHit( animevent_t *pEvent, CBaseCombatCharacter *pOperator );
};

#endif // WEAPON_SUITCASE_H
