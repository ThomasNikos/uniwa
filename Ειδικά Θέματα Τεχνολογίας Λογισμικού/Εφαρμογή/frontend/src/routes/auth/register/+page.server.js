import { fail } from '@sveltejs/kit';

export const actions = {
    default: async ({ request }) => {
        
        const data = await request.formData();
        const username = data.get('username');
        const password = data.get('password');
        const email = data.get('email');
        const address = data.get('address');
        const phone = data.get('phone');
        const role = 'user';
        const created_at = Date.now();

        try {
            const response = await fetch('http://localhost:3000/api/register', {
                method: 'POST',
                headers: {
                    'Content-Type': 'application/json',
                },
                body: JSON.stringify({
                    username,
                    password,
                    email,
                    address,
                    phone,
                    role,
                    created_at
                }),
            });

            if (!response.ok) {
                const errorData = await response.json();
                console.error("Registration error:", errorData);
                console.log(errorData);
                return fail(400, { 
                    registrationFailed: true,
                    error: errorData
                 });
            }

            const responseData = await response.json();
            console.log("Response from api: ",responseData);
            
            return { 
                success: true, 
                user: responseData.user,
                token:responseData.token
            };
        } catch (error) {
            console.error('Error during registration:', error);
            return { error: 'Something went wrong' };
        }
    }
};
