<script>
    // @ts-nocheck
    import { goto } from '$app/navigation';
    import { writable, get } from 'svelte/store';
    import { authStore } from '$lib/stores/auth';
    import { onMount } from 'svelte';

    let appointments = [];
    let isLoading = true;
    let error = null;

	const handleHome = () => {
        goto('/');
    };


    onMount(async () => {
        const auth = get(authStore);
        if (!auth?.token) {
            console.log(auth);
            goto('/auth/login');
            return;
        }

        try {
            const response = await fetch('http://localhost:3000/api/appointments/admin', {
                headers: {
                    'Authorization': `Bearer ${auth.token}`
                }
            });

            if (!response.ok) {
                throw new Error('Failed to fetch appointments');
            }

            appointments = await response.json();
        } catch (err) {
            error = err.message;
        } finally {
            isLoading = false;
        }
    });

    function formatDate(dateString) {
        const date = new Date(dateString);
        return new Intl.DateTimeFormat('el-GR', {
            day: '2-digit',
            month: '2-digit',
            year: 'numeric',
            hour: '2-digit',
            minute: '2-digit'
        }).format(date);
    }
</script>


<div class="container mx-auto px-4 py-8">
	 <!-- Back to Home Button -->
	 <button
	 on:click={handleHome}
	 class="group mb-4 flex items-center gap-2 px-4 py-2 bg-comb-cyan hover:bg-comb-blue text-white rounded-xl transition-all duration-300 shadow-md hover:shadow-lg"
 >
	 <svg
		 xmlns="http://www.w3.org/2000/svg"
		 width="20"
		 height="20"
		 fill="none"
		 stroke="currentColor"
		 stroke-width="2"
		 stroke-linecap="round"
		 stroke-linejoin="round"
		 class="transition-transform duration-300 group-hover:-translate-x-1"
	 >
		 <path stroke="none" d="M0 0h24v24H0z"/>
		 <path d="M5 12h14M5 12l4 4M5 12l4 -4"/>
	 </svg>
	 <span class="font-medium">Επιστροφή στην αρχική</span>
 </button>
    <div class="bg-white rounded-2xl shadow-xl p-6">
        <div class="flex justify-between items-center mb-6">
            <h1 class="text-3xl font-bold text-comb-gray">Admin Dashboard</h1>
            <span class="bg-comb-cyan text-white px-4 py-2 rounded-xl font-medium">
                Συνολικά Ραντεβού: {appointments.length}
            </span>
        </div>
        
        {#if isLoading}
            <div class="flex justify-center items-center h-40">
                <div class="animate-spin rounded-full h-12 w-12 border-b-2 border-comb-cyan"></div>
            </div>
        {:else if error}
            <div class="bg-red-100 border border-red-400 text-red-700 px-4 py-3 rounded">
                {error}
            </div>
        {:else}
            <div class="overflow-x-auto">
                <table class="w-full bg-white">
                    <thead>
                        <tr>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium rounded-tl-xl">#ID</th>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium">Ημερομηνία</th>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium">Πελάτης</th>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium">Email</th>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium">Τηλέφωνο</th>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium">Υπηρεσία</th>
                            <th class="px-6 py-4 bg-comb-cyan text-white text-left font-medium rounded-tr-xl">Υπάλληλος</th>
                        </tr>
                    </thead>
                    <tbody>
                        {#each appointments as { appointment, user }, i}
                            <tr class="hover:bg-gray-50 transition-colors duration-150">
                                <td class="px-6 py-4 border-b border-gray-200 text-comb-gray font-medium">
                                    #{appointment.id}
                                </td>
                                <td class="px-6 py-4 border-b border-gray-200 text-comb-gray">
                                    {formatDate(appointment.date)}
                                </td>
                                <td class="px-6 py-4 border-b border-gray-200 text-comb-gray font-medium">
                                    {user.username}
                                </td>
                                <td class="px-6 py-4 border-b border-gray-200">
                                    <a href="mailto:{user.email}" class="text-comb-cyan hover:text-comb-blue transition-colors">
                                        {user.email}
                                    </a>
                                </td>
                                <td class="px-6 py-4 border-b border-gray-200">
                                    <a href="tel:{user.phone}" class="text-comb-cyan hover:text-comb-blue transition-colors">
                                        {user.phone}
                                    </a>
                                </td>
                                <td class="px-6 py-4 border-b border-gray-200 text-comb-gray">
                                    {appointment.type}
                                </td>
                                <td class="px-6 py-4 border-b border-gray-200 text-comb-gray">
                                    {appointment.employee}
                                </td>
                            </tr>
                        {/each}
                    </tbody>
                </table>
            </div>
        {/if}
    </div>
</div>


<style>
    .overflow-x-auto {
        scrollbar-width: thin;
        scrollbar-color: theme('colors.comb-cyan') #E5E7EB;
    }

    .overflow-x-auto::-webkit-scrollbar {
        height: 8px;
    }

    .overflow-x-auto::-webkit-scrollbar-track {
        background: #E5E7EB;
        border-radius: 4px;
    }

    .overflow-x-auto::-webkit-scrollbar-thumb {
        background-color: theme('colors.comb-cyan');
        border-radius: 4px;
    }

    table {
        border-collapse: separate;
        border-spacing: 0;
    }
</style>