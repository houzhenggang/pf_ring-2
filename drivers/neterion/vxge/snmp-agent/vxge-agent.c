/**
 * NET-SNMP agent for Neterion Inc's X3100 Series 
 * 10Gbps network Adapters.
 * 
 * Copyright(c) 2002-2010 Exar Inc.
 *
 * This software may be used and distributed according to the terms of
 * the GNU General Public License (GPL), incorporated herein by reference.
 * Software based on or derived from this code fall under the GPL and must
 * retain the authorship, copyright and license notice.  This file is not
 * a complete program and may only be used when the entire operating
 * system is licensed under the GPL.
 * See the file COPYING in this distribution for more information.
 *
 * vxge-agent.c : integrates this agent with core net-snmp
 */ 

/*
 * Note: this file originally auto-generated by mib2c using
 *        : mib2c.old-api.conf 14476 2006-04-18 17:36:51Z hardaker $
 */

#include "vxge-agent.h"
#include "vxge-data.h"
#include "vxge-dev.h"

extern struct vxge_trap_info vxge_trap;
/*
 * vxge_variables_oid:
 *   this is the top level oid that we want to register under.  This
 *   is essentially a prefix, with the suffix appearing in the
 *   variable below.
 */
oid vxge_variables_oid[] = { 1, 3, 6, 1, 4, 1, 12808, 1, 2 };

/*
 * variable7 vxge_variables:
 *   this variable defines function callbacks and type return information 
 *   for the vxge mib section 
 */
struct variable7 vxge_variables[] = {
	/*
	 * magic number, variable type, ro/rw, callback fn, L, oidsuffix 
	 * where (L = length of the oidsuffix) 
	 */
	{VXGEGENVENDORNAME,     ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 1, 1}},
	{VXGEGENPRODUCTDESC,    ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 1, 2}},
	{VXGEGENHOSTNAME,       ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 1, 3}},
	{VXGEGENHOSTOS,         ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 1, 4}},
	{VXGEGENMIBVERSION,     ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 1, 5}},
	{VXGEGENVERSION,        ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 1, 6}}, 
	{VXGEGENDRIVERSTATUS,   ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 1, 7}},
	{VXGEBDNAME,            ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 2, 1}},
	{VXGEBDVERSION,         ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 2, 2}},
	{VXGEBDDATE,            ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 2, 3}},
	{VXGEBDSPEED,           ASN_OCTET_STR, RONLY,  var_vxge,            3, 
		{1, 2, 4}},
	{VXGEBDINTRTYPE,        ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 5}},
	{VXGEBDDOORBELL,        ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 7}},
	{VXGEBDLRO,             ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 10}},
	{VXGEBDLROMAXPKT,       ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 11}},
	{VXGEBDNAPI,            ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 12}},
	{VXGEBDVLANTAGSTRIP,    ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 13}},
	{VXGEBDRXSTEERING,      ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 14}},
	{VXGEBDTXSTEERING,      ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 2, 15}},
	{VXGEDEVICEIFACECOUNT,  ASN_INTEGER,   RONLY,  var_vxge,            3, 
		{1, 3, 1}},
	{VXGEDTENABLE,          ASN_INTEGER,   RWRITE, var_vxge,            3, 
		{2, 1, 2}},
	{VXGEDEINDEX,           ASN_UNSIGNED,  RONLY,  var_vxgeDeviceTable, 5, 
		{1, 3, 2, 1, 1}},
	{VXGEDEDESC,            ASN_OCTET_STR, RONLY,  var_vxgeDeviceTable, 5, 
		{1, 3, 2, 1, 2}},
	{VXGEDEPCIBDF,          ASN_OCTET_STR, RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 10}},
	{VXGEDEVENDORID,        ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 11}},
	{VXGEDEDEVICEID,        ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 12}},
	{VXGEDEIRQ,             ASN_UNSIGNED,  RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 13}},
	{VXGEDEFUNCMODE,        ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 14}},
	{VXGEDEACCESSRIGHT,     ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 20}},
	{VXGEDEBANDWIDTH,       ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 21}},
	{VXGEDEVPATHCOUNT,      ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 22}},
	{VXGEDELINKMODE,        ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 23}},
	{VXGEDEACTIVELINK,      ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 24}},
	{VXGEDEPERMMAC,         ASN_OCTET_STR, RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 25}},
	{VXGEDECURRENTMAC,      ASN_OCTET_STR, RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 30}},
	{VXGEDEACTIVELINKSTATE, ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 31}},
	{VXGEDEMTU,             ASN_UNSIGNED,  RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 32}},
	{VXGEDERXCSUM,          ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 33}},
	{VXGEDETXCSUM,          ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 34}},
	{VXGEDETSO,             ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 35}},
	{VXGEDEUFO,             ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 36}},
	{VXGEDESG,              ASN_INTEGER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 37}},
	{VXGEDETXINTRCOUNT,     ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 50}},
	{VXGEDERXINTRCOUNT,     ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 51}},
	{VXGEDECOLLISION,       ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 52}},
	{VXGEDERXMULTICAST,     ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 53}},
	{VXGEDERXBYTES,         ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 54}},
	{VXGEDERXPACKETS,       ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 55}},
	{VXGEDERXDROPPED,       ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 56}},
	{VXGEDERXERRORS,        ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 57}},
	{VXGEDETXBYTES,         ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 58}},
	{VXGEDETXPACKETS,       ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 59}},
	{VXGEDETXDROPPED,       ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 60}},
	{VXGEDETXERRORS,        ASN_COUNTER,   RONLY,  var_vxgeDeviceTable, 5,
		{1, 3, 2, 1, 61}},
};



/** Initializes the vxge module */
void
init_vxge(void)
{

    DEBUGMSGTL(("vxge", "Initializing vxge agent\n"));

    /*
     * register ourselves with the agent to handle our mib tree 
     */
    REGISTER_MIB("vxge", vxge_variables, variable7, vxge_variables_oid);

    /*
     * place any other initialization junk you need here 
     */
}

/*
 * var_vxge():
 *   This function is called every time the agent gets a request for
 *   a scalar variable that might be found within your mib section
 *   registered above.  It is up to you to do the right thing and
 *   return the correct value.
 *     You should also correct the value of "var_len" if necessary.
 *
 *   Please see the documentation for more information about writing
 *   module extensions, and check out the examples in the examples
 *   and mibII directories.
 */
unsigned char  *
var_vxge(struct variable *vp, oid *name, size_t *length, 
		int exact, size_t *var_len, WriteMethod **write_method)
{
	struct vxge_data obj = {0};
	
	if (header_generic(vp, name, length, exact, var_len, 
				write_method) == MATCH_FAILED) {
		DEBUGMSGTL(("vxge", "scalar header match failed\n"));
		return NULL;
	}
	
	obj.vp           = vp;
	obj.name         = name;
	obj.name_len     = length;
	obj.var_len      = var_len;
	obj.write_method = write_method;

	return vxge_get_scalar(&obj);
}


/*
 * var_vxgeDeviceTable():
 *   Handle this table separately from the scalar value case.
 *   The workings of this are basically the same as for var_vxge above.
 */
unsigned char *
var_vxgeDeviceTable(struct variable *vp, oid *name, size_t *length,
		int exact, size_t *var_len, WriteMethod **write_method)
{
	struct vxge_data obj = {0};
	int table_size;

	if ((table_size = vxge_dev_table_size()) <= 0) {
		//DEBUGMSGTL(("vxge", "wrong table size\n"));
		vxge_log("wrong table size (%d)\n", table_size);
		return NULL;
	}

    	/*
	 * This assumes that the table is a 'simple' table.
	 * See the implementation documentation for the meaning of this.
	 * You will need to provide the correct value for the TABLE_SIZE 
	 * parameter 
	 * If this table does not meet the requirements for a simple table,
	 * you will need to provide the replacement code yourself.
	 * Mib2c is not smart enough to write this for you.
	 * Again, see the implementation documentation for what is required.
	 */
    	if (header_simple_table(vp, name, length, exact, var_len, 
				write_method, table_size) == MATCH_FAILED) {
		//DEBUGMSGTL(("vxge", "table header match failed\n"));
		int i, o=0;
		char str[256], g[256];
		for (i=0;i<*length;i++)
			o+=sprintf(str+o, "%u.", (unsigned)name[i]);
		for (i=0,o=0;i<vp->namelen;i++)
			o+=sprintf(g+o, "%u.", (unsigned)vp->name[i]);
		vxge_log("table header match failed table size %d "
				"given_name %s exact %d true_name %s\n",
				table_size, str, exact, g);
		return NULL;
	}
	/* find table index */
	obj.table_index  = name[*length - 1];

	obj.vp           = vp;
	obj.name         = name;
	obj.name_len     = length;
	obj.var_len      = var_len;
	obj.write_method = write_method;

	return vxge_get_table_entry(&obj);
}

/*
 * write_vxgeDTEnable():
 *   function callback for enabling trap. this is write_method
 *   registered for mib object vxgeDTEnable
 */
int
write_vxgeDTEnable(int action, u_char * var_val, 
		u_char var_val_type, size_t var_val_len, 
		u_char * statP, oid * name, size_t name_len)
{
	static long value;
	static int op;
	int  size;
	int err = SNMP_ERR_NOERROR;
	
	switch (action) {
	case RESERVE1:
		if (var_val_type != ASN_INTEGER) {
			fprintf(stderr, "write to vxge not ASN_INTEGER\n");
			return SNMP_ERR_WRONGTYPE;
		}
		if (var_val_len > sizeof(long)) {
			fprintf(stderr, "write to vxge: bad length\n");
			return SNMP_ERR_WRONGLENGTH;
		}
		break;
	
	case RESERVE2:
		size = var_val_len;
		value = !!(*(long *) var_val);
		break;
	
	case FREE:
		/* Release any resources that have been allocated */
		break;
	
	case ACTION:
        	/*
		 * The variable has been stored in 'value' for you to use,
		 * and you have just been asked to do something with it.
		 * Note that anything done here must be reversable in the 
		 * UNDO case
		 */
		if (value && !vxge_get_driver_status()) {
			vxge_log("Driver not loaded, hence trap "
					"cannot be enabled\n");
			err = SNMP_ERR_COMMITFAILED;
			break;
		}
		if (vxge_trap.notify != value)
			op = 1;
        	break;
	
	case UNDO:
        	/* Back out any changes made in the ACTION case */
		op = 0;
		break;
	
	case COMMIT:
		/*
		 * Things are working well, so it's now safe to make the 
		 * change permanently.  Make sure that anything done 
		 * here can't fail!
		 */
		if (op == 1) {
			vxge_trap_manage(&vxge_trap, value);
		}
		op = 0;
		break;
	}
	return err;
}

void vxgeagent_trap_send(oid trap_id)
{
	/* snmpTrapOID.0 */
	static oid oid_snmptrap[] = { 1, 3, 6, 1, 6, 3, 1, 1, 4, 1, 0};
	static oid oid_vxgetrap[] = { 1, 3, 6, 1, 4, 1, 12808, 1, 2, 
		2, 1, 1, 0};
	static netsnmp_variable_list var_trap;

	oid_vxgetrap[12]       = trap_id;
	var_trap.next_variable = NULL;
	var_trap.name          = oid_snmptrap;
	var_trap.name_length   = sizeof(oid_snmptrap) / sizeof(oid);
	var_trap.type          = ASN_OBJECT_ID;
	var_trap.val.objid     = oid_vxgetrap;
	var_trap.val_len       = sizeof(oid_vxgetrap);
	send_v2trap(&var_trap);

	vxge_log("vxge trap %u sent to snmp\n", (unsigned)trap_id);
}

